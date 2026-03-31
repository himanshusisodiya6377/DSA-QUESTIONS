class Solution {
public:
class DSU{
        public:
        vector<int>parent,rank;
        int component;

        DSU(int n){
            parent.resize(n,0);
            component=n;
            for(int i=0;i<n;i++) parent[i]=i;
            rank.resize(n,0);
        }

        int find(int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }

        void Union(int x,int y){
            int par_x=find(x);
            int par_y=find(y);

            if(par_x==par_y) return ;

            if(rank[par_x]<rank[par_y]){
               parent[par_x]=par_y;
               rank[par_y]++;
            }
            else{
               parent[par_y]=par_x;
               rank[par_x]++;
            }
            component--;
        }

        // int component(){
        //     int cmp=0;

        //     for(int i=0;i<parent.size();i++){
        //         if(parent[i]==i && rank[parent[i]]>=1) cmp++;
        //     }

        //     return cmp;
        // }
    };
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edge, vector<vector<int>>& q) {
        vector<bool>ans(q.size(),false);

        // map<vector<int>,int>mp;
        vector<vector<int>>qu;

        for(int i=0;i<q.size();i++) qu.push_back({q[i][0],q[i][1],q[i][2],i});

        sort(qu.begin(),qu.end(),[](vector<int>&a,vector<int>&b){
           return a[2]<b[2];
        });

        // for(auto &it : qu) cout<<it[2]<<" ";
        sort(edge.begin(),edge.end(),[](vector<int>&a,vector<int>&b){
           return a[2]<b[2];
        });

        int i=0,j=0;
        DSU ds(n);

        while(j<qu.size()){
            while(i<edge.size() && edge[i][2]<qu[j][2]){
               ds.Union(edge[i][1],edge[i][0]);
               i++;
            }
            // cout<<i<<" "<<j<<endl;
            if(ds.find(qu[j][0])==ds.find(qu[j][1])) ans[qu[j][3]]=true;
            j++;
        }
        return ans;
    }
};