class Solution {
  public:
  
  void dfs(int i,stack<int>&st,vector<int>&visit,vector<vector<int>>&adj){
          visit[i]=1;
          for(auto it : adj[i]){
              if(visit[it]==0){
                  dfs(it,st,visit,adj);
              }
          }
          
          st.push(i);
   }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>topo;
        vector<vector<int>>adj(V);
        stack<int>st; 
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>visit(V,0);
        
        for(int i=0;i<V;i++){
            if(visit[i]==0){
                dfs(i,st,visit,adj);
            }
        }
        
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        
        return topo;
    }
};