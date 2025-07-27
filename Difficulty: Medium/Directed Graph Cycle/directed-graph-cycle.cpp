class Solution {
  public:
  
   bool dfs(int node,int parent,vector<int>&visit,vector<int>&pathvisit,vector<vector<int>>&adj){
      visit[node]=1;
      pathvisit[node]=1;
      
      for(auto it : adj[node]){
          if(visit[it]==0){
              if(dfs(it,node,visit,pathvisit,adj)) return true;
          }
          else if(pathvisit[it]==1) return true;
      }
      
      pathvisit[node]=0;
      return false;
   }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            // adj[it[1]].push_back(it[0]);
        }
        
        vector<int>visit(V,0);
        vector<int>pathvisit(V,0);
        
        for(int i=0;i<V;i++){
            if(visit[i]==0){
                if(dfs(i,-1,visit,pathvisit,adj)==true) return true;
            }
        }
        return false;
    }
};