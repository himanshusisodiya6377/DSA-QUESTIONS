class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n=nums1.size();

        vector<pair<long long,long long>>v;

        for(int i=0;i<n;i++) v.push_back({nums2[i],nums1[i]});
        sort(v.begin(),v.end());

        int i=n-1;
        long long sum=0;
        
        priority_queue<int,vector<int>,greater<int>>pq; //minimum at top 
        long long ans=0;

        while(i>=0){
           
           if(n-i>=k){
             ans=max(ans,1LL*v[i].first*(sum+v[i].second)); 
             if(!pq.empty() && pq.size()==k-1 && pq.top()<v[i].second){
                sum-=pq.top();
                pq.pop();
                sum+=v[i].second;
                pq.push(v[i].second);
              }     
           }
           else{
              if(!pq.empty() && pq.size()==k-1 && pq.top()<v[i].second){
                sum-=pq.top();
                pq.pop();
                sum+=v[i].second;
                pq.push(v[i].second);
              }
              else {
                sum+=v[i].second;
                pq.push(v[i].second);
              }
           }
           i--;
        }
       return ans;
    }
};