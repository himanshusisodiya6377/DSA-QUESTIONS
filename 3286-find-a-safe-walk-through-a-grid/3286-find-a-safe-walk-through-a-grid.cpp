class Solution {
public:
    int dp[101][51][51];

    bool dfs(vector<vector<int>>& grid, int r, int c,
             int health, int i, int j) {

        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 2)
            return false;

        if (grid[i][j] == 1)
            health--;

        if (health <= 0)
            return false;

        if (i == r - 1 && j == c - 1)
            return true;

        if (dp[health][i][j] != -1)
            return dp[health][i][j];

        int temp = grid[i][j];
        grid[i][j] = 2;

        bool flag =
            dfs(grid, r, c, health, i + 1, j) ||
            dfs(grid, r, c, health, i - 1, j) ||
            dfs(grid, r, c, health, i, j + 1) ||
            dfs(grid, r, c, health, i, j - 1);

        grid[i][j] = temp;

        return dp[health][i][j] = flag;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        memset(dp, -1, sizeof(dp));

        return dfs(grid, grid.size(), grid[0].size(),
                   health, 0, 0);
    }
};