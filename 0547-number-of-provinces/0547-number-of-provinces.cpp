class Solution {
public:
    unordered_map<int, vector<int>> ls;
    void creatls(vector<vector<int>>& isConnected, bool bi_dir) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    ls[i + 1].push_back(j + 1);
                    ls[j + 1].push_back(i + 1);
                }
            }
        }
    }
    void dfs(vector<vector<int>>& isConnected, vector<int>& visit, int source) {
        if (visit[source] == 1)
            return;
        visit[source] = 1;
        for (auto neigh : ls[source]) {
            if (visit[neigh] == 0) {
                dfs(isConnected, visit, neigh);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visit(n + 1, 0);
        creatls(isConnected, true);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visit[i + 1] == 0) {
                ans++;
                dfs(isConnected, visit, i + 1);
            }
        }
        return ans;
    }
};