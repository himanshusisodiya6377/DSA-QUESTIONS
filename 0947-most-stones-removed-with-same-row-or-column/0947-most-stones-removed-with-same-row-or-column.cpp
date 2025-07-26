class Solution {
public:

   int find(int node,vector<int>&parent){
    if(node==parent[node]) return parent[node];
    return parent[node]=find(parent[node],parent);
   }

   void uniongp(int u,int v,vector<int>&parent,vector<int>&rank){
     
     int par_u=find(u,parent);
     int par_v=find(v,parent);

     if(par_u==par_v) return;

     if(rank[par_u]<rank[par_v]){
          parent[par_u]=par_v;
     }
     else if(rank[par_v]<rank[par_u]){
         parent[par_v]=par_u;
     }
     else{
          parent[par_u]=par_v;
          rank[par_v]++;
     }

     return;
   }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0,maxcol=0;
        for(int i=0;i<n;i++){
            maxrow=max(maxrow,stones[i][0]);
            maxcol=max(maxcol,stones[i][1]);
        }
        vector<int>rank(maxrow+maxcol+2,0);
        vector<int>parent(maxrow+maxcol+2);
        for(int i=0;i<(maxrow+maxcol+2);i++){
            parent[i]=i;
        }
       
       set<int>st;
       for(auto it : stones){
         int row=it[0];
         int col=it[1]+maxrow+1;
         uniongp(row,col,parent,rank);
         st.insert(row);
         st.insert(col);
       }
          
        int cnt=0;

        for(auto it : st){
            if(find(it,parent)==it) cnt++;
        }

       return n-cnt;

    }
};