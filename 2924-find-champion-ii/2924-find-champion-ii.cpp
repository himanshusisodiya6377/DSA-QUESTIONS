class Solution {
public:

    void dfs( int source,unordered_map<int,vector<int>>&mp,unordered_set<int>&visit){
            for(auto neigh:mp[source]){
                if(visit.find(neigh)==visit.end()){
                    visit.insert(neigh);
                    dfs(neigh,mp,visit);
                }
            }        
    }

    int findChampion(int n, vector<vector<int>>& edges) {
         unordered_map<int,vector<int>>mp;
         if(edges.size()==0 && n==1) return 0;
         if(edges.size()==0 && n>1) return -1;
         int r=edges.size();
         for(int i=0;i<r;i++){
                mp[edges[i][0]].push_back(edges[i][1]);
         }   
         unordered_set<int>visit;
         int source;
         for(int i=0;i<n;i++){
            bool flag=false;
            for(auto v : mp){
                for(auto p : v.second){
                    if(i==p){
                        flag=true;
                        break;
                    }
                }
                if(flag==true) break;
            }
            if(flag==false){
                source=i;
            }
         }
         
         
         visit.insert(source);
        dfs(source,mp,visit);
        if(visit.size()==n){
        return source;
        }
        else return -1;
    }
};