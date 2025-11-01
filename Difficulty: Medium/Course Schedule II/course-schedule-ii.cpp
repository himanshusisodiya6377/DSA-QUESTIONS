class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        unordered_map<int,vector<int>>adj;
        unordered_map<int,vector<int>>adjdir;
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
            adjdir[it[1]].push_back(it[0]);
        }
        
        vector<int>indegree(n,0);
        for(auto it : adj){
            indegree[it.first]=it.second.size();
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto it : adjdir[x]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        // for(auto it : ans) cout<<it<<" ";
        
        return ans;
    }
};