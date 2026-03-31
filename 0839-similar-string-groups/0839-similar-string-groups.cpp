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
    };
    bool check(string &a,string &b){
        if(a.length()!=b.length()) return false;
        int cnt=0;

        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]) cnt++;
        }

        return cnt<=2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();

        unordered_map<string,int>mp;
        int node=0;

        for(auto &it : strs){
            if(mp.find(it)==mp.end()){
                mp[it]=node;
                node++;
            }
        }

       DSU ds(node);
       
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(check(strs[i],strs[j])){
                ds.Union(mp[strs[i]],mp[strs[j]]);
            }
        }
       }

       return ds.component;
    }
};