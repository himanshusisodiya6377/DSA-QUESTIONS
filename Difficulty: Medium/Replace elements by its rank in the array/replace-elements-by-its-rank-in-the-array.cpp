// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        
        int rank=1;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &it : arr) pq.push(it);
        
        unordered_map<int,int>mp;
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            
            if(mp.find(p)==mp.end()){
                mp[p]=rank;
                rank++;
            }
        }
        
        // for(auto &it : mp) cout<<it.first<<" "<<it.second<<endl;
        
        vector<int>ans(N,0);
        
        int i=0;
        for(auto &it : arr){
            ans[i]=mp[it];
            i++;
        }
        
        return ans;
        
    }
};
