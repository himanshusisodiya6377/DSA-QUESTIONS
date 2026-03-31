class Solution {
public:
    class DSU{
        public:
        vector<int>parent,rank;

        DSU(){
            parent.resize(26,0);
            for(int i=0;i<26;i++) parent[i]=i;
        }

        int find(int ch){
           if(parent[ch]==ch) return parent[ch];
           return parent[ch]=find(parent[ch]);
        }

        void Union(int x,int y){
            int par_x=find(x);
            int par_y=find(y);

            if(par_x==par_y) return;

            parent[par_x]=par_y;
        }
    };
    bool equationsPossible(vector<string>& eq) {
        
        int n=eq.size();

        DSU ds;

        for(auto &it : eq){
            //those need to be in same group
            if(it[1]=='='){
                ds.Union(it[0]-'a',it[3]-'a');
            }
        }

        for(auto &it : eq){
            if(it[1]=='!' && ds.find(it[0]-'a')==ds.find(it[3]-'a')){
              return false;
            }
        }

        return true;
    }
};