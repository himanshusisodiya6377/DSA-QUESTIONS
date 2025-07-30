// User function Template for C++
class Solution {
  public:
  
    void topo(int node,stack<int>&st,vector<int>&visit,vector<vector<pair<int,int>>>&adj){
        visit[node]=1;
        
        for(auto it : adj[node]){
           
                if(visit[it.first]==0){
                    topo(it.first,st,visit,adj);
                }
            
        }
        
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        //creation of adjacency list
        vector<vector<pair<int,int>>>adj(V);
        vector<int>dist(V,INT_MAX);
        dist[0]=0;
        
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        
        vector<int>visit(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(visit[i]==0){
                topo(i,st,visit,adj);
            }
        }
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
           if (dist[node] != INT_MAX) {
           for (auto it : adj[node]) {
           if (dist[it.first] > dist[node] + it.second) {
            dist[it.first] = dist[node] + it.second;
           }
           }
        }

        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        
        return dist;
    }
};
