class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int N;
    vector<int> moves;
    vector<int> degree;
    vector<int> parent;

    // Find parent of every node
    void findParent(int node, int par) {
        parent[node] = par;
        for (int child : adj[node]) {
            if (child != par)
                findParent(child, node);
        }
    }

    int bfs_alice(int node, vector<int>& amount) {
        vector<bool> visit(N, false);

        queue<vector<int>> q;

        int price = 0;

        if (moves[0] > 0)
            price += amount[0];
        else if (moves[0] == 0)
            price += amount[0] / 2;

        q.push({0, price, 0});   // node, profit, time
        visit[0] = true;

        int ans = INT_MIN;

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int nd = p[0];
            int pri = p[1];
            int tm = p[2];

            // leaf
            if (nd != 0 && degree[nd] == 1)
                ans = max(ans, pri);

            // single node tree
            if (N == 1)
                ans = max(ans, pri);

            for (int nxt : adj[nd]) {

                if (visit[nxt]) continue;

                visit[nxt] = true;

                int gain = 0;

                if (moves[nxt] > tm + 1)
                    gain = amount[nxt];
                else if (moves[nxt] == tm + 1)
                    gain = amount[nxt] / 2;
                else
                    gain = 0;

                q.push({nxt, pri + gain, tm + 1});
            }
        }

        return ans;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {

        N = edges.size() + 1;

        moves.assign(N, INT_MAX);
        degree.assign(N, 0);
        parent.assign(N, -1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        // Build parent array
        findParent(0, -1);

        // Bob's arrival times (only on path to root)
        int t = 0;
        while (bob != -1) {
            moves[bob] = t++;
            bob = parent[bob];
        }

        return bfs_alice(0, amount);
    }
};