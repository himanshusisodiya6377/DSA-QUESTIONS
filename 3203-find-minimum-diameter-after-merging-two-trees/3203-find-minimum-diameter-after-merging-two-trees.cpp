class Solution {
public:
    pair<int,int> bfs(int src, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        int far = src;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            far = node;

            for (int nxt : adj[node]) {
                if (dist[nxt] != -1) continue;
                dist[nxt] = dist[node] + 1;
                q.push(nxt);
            }
        }

        return {far, dist[far]};
    }

    int diameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        auto p1 = bfs(0, adj);
        auto p2 = bfs(p1.first, adj);

        return p2.second;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {

        int d1 = diameter(edges1);
        int d2 = diameter(edges2);

        int r1 = (d1 + 1) / 2;
        int r2 = (d2 + 1) / 2;

        return max({d1, d2, r1 + r2 + 1});
    }
};