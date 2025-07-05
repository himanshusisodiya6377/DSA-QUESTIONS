class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        // priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        vector<int>ans;
        // for(auto v : mp){
        //   pq.push({v.second,v.first});
        // }
        // while(k>0){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        //     k--;
        // }
        vector<vector<int>>visit(n+1);
        for(auto v : mp){
            visit[v.second].push_back(v.first);
        }
        for(int i=n;i>=0 && k>0 ;i--){
            if(visit[i].size()==0) continue;
            for(int j=0;j<visit[i].size() && k>0;j++){
                ans.push_back(visit[i][j]);
                k--;
            }
        }
        return ans;
    }
};