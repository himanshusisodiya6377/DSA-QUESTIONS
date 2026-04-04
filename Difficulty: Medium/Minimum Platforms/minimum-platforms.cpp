class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<pair<int,int>>v;
        
        for(int i=0;i<arr.size();i++) v.push_back({arr[i],dep[i]});
        
        sort(v.begin(),v.end(),[](const pair<int,int>&a,const pair<int,int>&b){
          return a.first<b.first; 
        });
        // sort(v.begin(),v.end());
        
        // for(auto &it : v){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=0;
        
        for(auto &it : v){
            while(!pq.empty() && pq.top()<it.first){
                    pq.pop();
                }
            pq.push(it.second);
            n=max(n,(int)pq.size());
        }
        return n;
    }
};
