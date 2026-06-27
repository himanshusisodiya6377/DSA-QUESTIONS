class Solution {
public:
    vector<bool> visit;
    vector<int> color;
    bool bfs(int node,unordered_map<int, vector<int>> &adj) {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        visit[node] = true;

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int col = color[p];

            for (auto& it : adj[p]) {
                if (color[it] == col)
                    return false;
                if (!visit[it]) {
                    color[it] = 1 - col;
                    visit[it] = true;
                    q.push(it);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;

        int n = graph.size();
        for (int i = 0; i < n; i++) {
            for (auto& it : graph[i]) {
                adj[i].push_back(it);
            }
        }
        visit.resize(n, false);
        color.resize(n, -1);

        for(int i=0;i<n;i++){
            if(!visit[i] && !bfs(i,adj)) return false;
        }

        return true;
    }
};