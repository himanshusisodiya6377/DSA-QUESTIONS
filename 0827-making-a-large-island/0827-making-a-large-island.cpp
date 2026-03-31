class Solution {
public:
    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    class DSU{
        public:
        vector<int>size,parent;

        DSU(int n){
           size.resize(n,1);

           parent.resize(n,0);
           for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int x){
            if(x==parent[x]) return parent[x];
            return parent[x]=find(parent[x]);
        }

        void Union(int x,int y){
            int par_x=find(x);
            int par_y=find(y);

            if(par_x==par_y) return;

            if(size[par_x]<size[par_y]){
                parent[par_x]=par_y;
                size[par_y]+=size[par_x];
            }
            else{
                parent[par_y]=par_x;
                size[par_x]+=size[par_y];
            }
        }
    };
    int largestIsland(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();

        DSU ds(r*c);

        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0) continue;
                    int node=i*c+j;
                for(auto &it : dir){
                    int nr=i+it[0];
                    int nc=j+it[1];

                    if(nr<0 || nr>=r || nc<0 || nc>=c || grid[nr][nc]==0) continue;

                    int adj_node=nr*c+nc;

                    ds.Union(node,adj_node);
                }
                    ans=max(ans,ds.size[ds.find(node)]);
            }
        }

        // cout<<ans<<endl;


        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) continue;

                unordered_set<int>st;
                for(auto &it : dir){
                   int x=i+it[0];
                   int y=j+it[1];

                   if(x<0 || x>=r || y<0 || y>=c || grid[x][y]==0) continue;
                   int node=x*c+y;
                   st.insert(ds.find(node));
                }

                // cout<<st.size()<<endl;

                int sum=0;
                for(auto &it : st){
                    sum+=ds.size[it];
                }
                sum++;
                // cout<<sum<<" "<<st.size()<<endl;
                ans=max(ans,sum);
            }
        }

        return ans;
    }
};