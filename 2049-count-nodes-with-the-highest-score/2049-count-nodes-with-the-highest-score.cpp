class Solution {
public:
    long long mx = 0;
    int cnt = 0;
    int n;

    int dfs(vector<vector<int>>& adj, int node) {

        int left = 0, right = 0;

        if (adj[node].size() >= 1)
            left = dfs(adj, adj[node][0]);

        if (adj[node].size() >= 2)
            right = dfs(adj, adj[node][1]);

        int parent = n - left - right - 1;

        long long score = 1LL;
        score *= max(1, left);
        score *= max(1, right);
        score *= max(1, parent);

        if (score > mx) {
            mx = score;
            cnt = 1;
        } else if (score == mx) {
            cnt++;
        }

        return left + right + 1;
    }

    int countHighestScoreNodes(vector<int>& parent) {

        n = parent.size();

        vector<vector<int>> adj(n);
        int root = 0;

        for (int i = 0; i < n; i++) {
            if (parent[i] == -1)
                root = i;
            else
                adj[parent[i]].push_back(i);
        }

        dfs(adj, root);

        return cnt;
    }
};