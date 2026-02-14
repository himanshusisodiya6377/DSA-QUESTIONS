class Graph {
public:
    unordered_map<int,vector<pair<int,int>>>adj; //node -> {node,weight}
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        for(auto & it : edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
    }
    
    void addEdge(vector<int> it) {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(N+1,INT_MAX);
        dist[node1]=0;
        priority_queue<pair<int,int>>pq;
        pq.push({node1,0});

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();

            int node=p.first;
            int wt=p.second;

            if(dist[node]<wt) continue;

            for(auto &it : adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                    pq.push({it.first,dist[it.first]});
                }
            }
        }

        return (dist[node2]==INT_MAX ? -1 : dist[node2]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */