class Solution {
public:
      typedef pair<int,pair<int,int>> pp;
    vector<vector<int>> kSmallestPairs(vector<int>& arr1, vector<int>& arr2, int k) {
         int n=arr1.size();
        int m=arr2.size();
        //int i=0,j=0;
        vector<vector<int>>ans;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push({arr1[i]+arr2[j],{arr1[i],arr2[j]}});
            }
        }
        
        while(k--){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        // while(k--){
        //     ans.push_back({arr1[i],arr2[j]});
        //     cout<<arr1[i]<<" "<<arr2[j]<<endl;
        //     if(i<n && j<m){
        //         if(arr1[i+1]<arr2[j+1]) i++;
        //         else j++;
        //     }
        // }
        return ans;
    }
};