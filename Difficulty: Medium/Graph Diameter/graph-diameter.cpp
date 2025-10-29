class Solution {
  public:
    int bfs(int start,unordered_map<int,vector<int>>&adj,vector<bool>&visit,bool flag){
        queue<int>q;
        q.push(start);
        visit[start]=true;
        int temp=start;
        int  len=0;
        while(!q.empty()){
            int n=q.size();
            len++;
            for(int i=0;i<n;i++){
                int x=q.front();
                q.pop();
                temp=x;
                // if(visit[x]) continue;
                for(auto it : adj[x]){
                   if(visit[it]) continue;
                   q.push(it);
                   visit[it]=true;
                }
            }
        }
        
        // cout<<temp.front();
        if(!flag) return temp;
        //  cout<<len;
        return len-1;
        
    }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>adj;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>visit(V,false);
        int node=bfs(0,adj,visit,false);
        visit=vector<bool>(V,false);
        return bfs(node,adj,visit,true);
    }
};
