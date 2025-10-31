class Solution {
  public:
  
    void bfs(int src, unordered_map<int,vector<int>>&adj, vector<bool>&visit,vector<int>&dist,int &ans){
        
        visit[src]=true;
        dist[src]=0;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            
            for(auto adjnode : adj[node]){
                if(!visit[adjnode]){
                    visit[adjnode]=true;
                    dist[adjnode]=(dist[node]+1);
                    q.push({adjnode,node});
                }
                else if(par!=adjnode){
                    // cout<<adjnode<<endl;
                    ans=min(ans,dist[adjnode]+dist[node]+1);
                    // return true;
                }
            }
        }
        // return false;
    }
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>mp;
        for(auto it : edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int ans=INT_MAX;
        for(int i=0;i<V;i++){
        vector<bool>visit(V,false);
        vector<int>dist(V,0);
        // int node=-1;
          
                // cout<<i<<" ";
                bfs(i,mp,visit,dist,ans);
            
            
            // if(node!=-1){
            //     ans=min(ans,distance(i,node));
            // }
        }
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};
