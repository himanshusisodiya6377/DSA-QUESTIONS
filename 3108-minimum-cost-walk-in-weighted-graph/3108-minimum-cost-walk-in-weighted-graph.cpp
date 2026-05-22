class Solution {
public:
    class DSU{
        public:
        vector<int>parent;
        vector<int>rank;
        vector<int>bitAnd;

        DSU(int n){
            parent.resize(n,0);
            rank.resize(n,0);
            bitAnd.resize(n,INT_MAX);

            for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int x){
            if(parent[x]==x) return parent[x];
            return parent[x]=find(parent[x]);
        }

        void Union(int x,int y,int wt){
            int par_x=find(x);
            int par_y=find(y);
            if (par_x == par_y) {
            bitAnd[par_x] &= wt;
            return;
            }
            
            if(rank[par_x]<rank[par_y]){
                parent[par_x]=par_y;
                bitAnd[par_y]&=wt;
                bitAnd[par_y]&=bitAnd[par_x];
            }
            else if(rank[par_x]>rank[par_y]){
                 parent[par_y]=par_x;
                  bitAnd[par_x]&=wt;
                   bitAnd[par_x]&=bitAnd[par_y];
            }
            else{
                  parent[par_x]=par_y;
                  rank[par_y]++;
                   bitAnd[par_y]&=wt;
                    bitAnd[par_y]&=bitAnd[par_x];
            }
        }
    };
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU ds(n);
        for(auto &it : edges){
            ds.Union(it[0],it[1],it[2]);
        }

        // for(auto &it : ds.bitAnd) cout<<it<<" ";

        vector<int>ans(query.size(),0);
        for(int i=0;i<query.size();i++){
            if(ds.find(query[i][0])!=ds.find(query[i][1])) ans[i]=-1;
            else{
                ans[i]=ds.bitAnd[ds.find(query[i][0])];
            }
        }
        return ans;
    }
};