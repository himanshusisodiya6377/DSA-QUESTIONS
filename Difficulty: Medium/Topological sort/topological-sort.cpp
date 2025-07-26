class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
       vector<vector<int>> adj(V);
       for(auto it : edges){
           adj[it[0]].push_back(it[1]);
       }
       
        vector<int>indegree(V,0);

        for(int i=0;i<adj.size();i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
   
       vector<int>topo;
       queue<int>q;

       for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
       }

       while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
       }

       return topo;
    }
};