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
//   bool dfs(int source,int dest,vector<int>&visit){
//     if(source==dest) return true;
//     visit[source]=1;
//     for(auto neigh : ls[source]){
//         if(visit[neigh]==0){
//             bool result=dfs(neigh,dest,visit);
//             if(result) return true;
//         }
//     }
//     return false;
//   }
  bool bfs(int source,int dest,vector<int>&visit,queue<int>&q){
    if(source==dest) return true;
    visit[source]=1;
    q.push(source);
   
    while(!q.empty()){
       int top=q.front();
      q.pop();
     for(int neigh : ls[top]){
        if(neigh==dest) return true;
        if(visit[neigh]==0){
            q.push(neigh);
            visit[neigh]=1;
        }
     }
    }
    return false;
  }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>visit(n,0);
        creatls(edges,true);
        queue<int>q;
        bool flag=bfs(source,destination,visit,q);
        // bool flag=dfs(source,destination,visit);
        return flag;
    }
};