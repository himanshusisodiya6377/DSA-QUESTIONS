class Solution {
public:
    class DSU{
        public: 
        vector<int>parent;
        vector<int>rank;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;

        DSU(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            for(int i=1;i<=n;i++){
                 parent[i]=i;
                 mp[i].push(i);
            }
        }

        int find(int x){
            if(parent[x]==x) return parent[x];
            return parent[x]=find(parent[x]);
        }

        void Union (int x,int y){
            int par_x=find(x);
            int par_y=find(y);

            if(par_x==par_y) return;

            if(rank[par_x]<rank[par_y]){
              
                while(!mp[par_x].empty()){
                    mp[par_y].push(mp[par_x].top());
                    parent[mp[par_x].top()]=par_y;
                    mp[par_x].pop();
                }
              
                parent[par_x]=par_y;

            }
            else if(rank[par_x]>rank[par_y]){

                 while(!mp[par_y].empty()){
                    mp[par_x].push(mp[par_y].top());
                    parent[mp[par_y].top()]=par_x;
                    mp[par_y].pop();
                }

                parent[par_y]=par_x;
            }
            else{
                while(!mp[par_x].empty()){
                    mp[par_y].push(mp[par_x].top());
                    parent[mp[par_x].top()]=par_y;
                    mp[par_x].pop();
                }
                parent[par_x]=par_y;
                rank[par_y]++;
            }
        }


    };
    vector<int> processQueries(int c, vector<vector<int>>& con, vector<vector<int>>& q) {
        int n=con.size();
        
        DSU ds(c);
        vector<int>ans;

        for(auto &it : con){
            int fir=it[0];
            int sec=it[1];

            ds.Union(fir,sec);
        }

        unordered_set<int>st;

        for(auto &it : q){
            int fir=it[0];
            int sec=it[1];
            
            while(!ds.mp[ds.parent[sec]].empty() && st.count(ds.mp[ds.parent[sec]].top())) ds.mp[ds.parent[sec]].pop();
            
            if(fir==1){
                   cout<<ds.parent[sec]<<endl;
                   if(st.find(sec)==st.end()) ans.push_back(sec);
                   else if(!ds.mp[ds.parent[sec]].empty()) ans.push_back(ds.mp[ds.parent[sec]].top());
                   else ans.push_back(-1);
            }
            else{
                 st.insert(sec);
            }
        }

        return ans;
    }
};