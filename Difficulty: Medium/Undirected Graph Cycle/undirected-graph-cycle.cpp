class Solution {
  public:
  
  bool dfs(int node,int parent,vector<int>&visit,vector<vector<int>>&adj){
      visit[node]=1;
      
      for(auto it : adj[node]){
          if(visit[it]==0){
              if(dfs(it,node,visit,adj)==true) return true;
          }
          else if(it!=parent) return true;
      }
      
      return false;
  }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>visit(V,0);
        
        for(int i=0;i<V;i++){
            if(visit[i]==0){
                if(dfs(i,-1,visit,adj)==true) return true;
            }
        }
        
        return false;
    }
};