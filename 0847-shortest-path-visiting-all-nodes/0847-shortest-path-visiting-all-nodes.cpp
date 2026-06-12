class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<graph.size();i++){
            for(auto &it : graph[i]){
                adj[i].push_back(it);
            }
        }

        queue<pair<int,int>>q;
        map<pair<int,int>,bool>visit;
        int n=graph.size();
        int final_mask=(1<<n)-1;
        // q.push({0,0,0}); // node  distance mask
        // visit[{0,0}]=true; //node mask
        
        for(int i=0;i<n;i++){
            q.push({i,1<<i});
            visit[{i,1<<i}]=true;
        }
        int dist=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            auto p=q.front();
            q.pop();

            int node=p.first;
            // int dist=p[1];
            int mask=p.second;

            if((mask )==final_mask) return dist;
            // cout<<"yes";
            // if(visit.count({node,mask})) continue;
            // visit[{node,mask}]=true;

            for(auto &it : adj[node]){
                if(!visit.count({it,(mask | (1<<it))})){
                    // cout<<"yes";
                    q.push({it,mask | (1<<it)});
                    visit[{it,mask | (1<<it)}]=true;
                }
            }
            }
            dist++;
        }
        cout<<"hi";
        return 0;
    }
};