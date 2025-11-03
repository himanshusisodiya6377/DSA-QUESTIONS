class Solution {
public:
    bool dfs(int node,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&mp){
        if(mp.find(node)!=mp.end()) return mp[node];
        mp[node]=false;
        for(auto it : adj[node]){
            if(!dfs(it,adj,mp)) return false;
        }
        mp[node]=true;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
                adj[i].push_back(it);
            }
        }

        unordered_map<int,bool>mp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end()){
                dfs(i,adj,mp);
            }
        }
        for(auto it : mp){
            if(it.second) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};