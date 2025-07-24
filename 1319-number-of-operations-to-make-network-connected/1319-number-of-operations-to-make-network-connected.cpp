class Solution {
public:
  

    int find(int node,vector<int>&parent){
        if(node==parent[node]) return parent[node];
        return parent[node]=find(parent[node],parent);
    }

    void unionfun(int u,int v,vector<int>&rank,vector<int>&parent){
      
      int par_u=find(u,parent);
      int par_v=find(v,parent);

      if(par_u==par_v) return;
      if(rank[par_u]<rank[par_v]) parent[par_u]=par_v;
      else if(rank[par_v]<rank[par_u]) parent[par_v]=par_u;
      else{
        parent[par_u]=par_v;
        rank[par_v]++;
      }

    }

    int makeConnected(int n, vector<vector<int>>& connections) {

    vector<int>parent(n);
    vector<int>rank(n,0);
    for(int i=0;i<n;i++) parent[i]=i;
    
    int cycle=0;
    int component=0;

    for(int i=0;i<connections.size();i++){
        vector<int>v=connections[i];

        int par_u=find(v[0],parent);
        int par_v=find(v[1],parent);

        if(par_u==par_v) cycle++;
        else{
            unionfun(par_u,par_v,rank,parent);
        }
    }
  
    set<int>st;

    for(int i=0;i<n;i++){
   st.insert(find(i, parent));
   }


    if(st.size()==1) return 0;

    if(cycle>=st.size()-1) return st.size()-1;
    else return -1;


    }
};