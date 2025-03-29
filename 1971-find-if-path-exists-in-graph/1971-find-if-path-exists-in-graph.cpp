class Solution {
public:
  unordered_map<int,vector<int>>ls;
  
  void creatls(vector<vector<int>>& edges,bool bi_dir){
    for(auto v : edges){
        int x=v[0];
        int y=v[1];
        ls[x].push_back(y);
        if(bi_dir){
            ls[y].push_back(x);
        }
    }
  }
  bool check(int source,int dest,vector<int>&visit){
    if(source==dest) return true;
    visit[source]=1;
    for(auto neigh : ls[source]){
        if(visit[neigh]==0){
            bool result=check(neigh,dest,visit);
            if(result) return true;
        }
    }
    return false;
  }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>visit(n,0);
        creatls(edges,true);
        bool flag=check(source,destination,visit);
        return flag;
    }
};