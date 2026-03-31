class Solution {
public:
    class DSU{
        public:

        vector<int>parent,size;
        DSU(int n){
            parent.resize(n+1,0);
            size.resize(n+1,1);

            for(int i=0;i<n+1;i++) parent[i]=i;
        }

        int find(int x){
            if(parent[x]==x) return x;
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
    bool possibleBipartition(int n, vector<vector<int>>& dis) {

       unordered_map<int,vector<int>>mp;

       for(auto &it : dis){
        mp[it[0]].push_back(it[1]);
        mp[it[1]].push_back(it[0]);
       }

       DSU ds(n);

       for(auto &it : mp){
          vector<int>t=it.second;
          if(t.size()<=1) continue;    
          for(int i=1;i<t.size();i++){
             ds.Union(t[0],t[i]);
          }
       }


       for(auto &it : dis){
        if(ds.find(it[0])==ds.find(it[1])) return false;
       }

       return true;


    }
};