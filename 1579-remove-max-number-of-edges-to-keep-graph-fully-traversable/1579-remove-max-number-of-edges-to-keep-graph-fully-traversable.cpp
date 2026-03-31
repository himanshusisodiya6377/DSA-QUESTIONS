class Solution {
public:
    class DSU{
        public:
        vector<int>parent,rank;
        int component;

        DSU(int n){
            parent.resize(n+1,0);
            component=n;
            for(int i=0;i<n+1;i++) parent[i]=i;
            rank.resize(n+1,0);
        }

        int find(int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }

        bool Union(int x,int y){
            int par_x=find(x);
            int par_y=find(y);

            if(par_x==par_y) return false;

            if(rank[par_x]<rank[par_y]){
               parent[par_x]=par_y;
               rank[par_y]++;
            }
            else{
               parent[par_y]=par_x;
               rank[par_x]++;
            }
            component--;
            return true;
        }

        // int component(){
        //     int cmp=0;

        //     for(int i=0;i<parent.size();i++){
        //         if(parent[i]==i) cmp++;
        //     }

        //     return cmp;
        // }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU a(n);
        DSU b(n);
        
        int ans=0;
        //doing for Alice
        set<vector<int>>st;
        for(auto &it : edges){
            if(it[0]==3){
                bool alice=a.Union(it[1],it[2]);
                bool bob=b.Union(it[1],it[2]);

                if(alice || bob) ans++;
            }
        }


        
        for(auto &it : edges){
            if(it[0]==1){
                if(a.Union(it[1],it[2])) ans++;
            }
        }
         for(auto &it : edges){
            if(it[0]==2){
                if(b.Union(it[1],it[2])) ans++;
            }
        }

        if(a.component>1) return -1;

        if(b.component>1) return -1;

        return edges.size()-ans;
    }
};