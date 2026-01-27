class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        
        int m=edges.size();

        unordered_map<int,vector<pair<int,int>>>adj; //node --> node + wt

        for(auto &it : edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }

        vector<int>dist(n,INT_MAX);
        dist[0]=0;

        priority_queue<pair<int,int>>pq;  //node + wt

        pq.push({0,0});

        while(!pq.empty()){

            auto p=pq.top();
            pq.pop();

            int node=p.first;
            int wt=p.second;

            if(wt>dist[node]) continue;

            for(auto &it : adj[node]){

                if(dist[node]!=INT_MAX && dist[node]+it.second<dist[it.first]){
                    pq.push({it.first,dist[node]+it.second});
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }

        return (dist[n-1]==INT_MAX ? -1 : dist[n-1]);
    }
};