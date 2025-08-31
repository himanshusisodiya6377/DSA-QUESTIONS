class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int i, int j,int dir) {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 1 ||
            grid[i][j] == 0)
            return;
            // if (grid[i][j] == 2) return;

        grid[i][j] = 2;

        // right
        if(dir==1 ) dfs(grid, row, col, i, j + 1,1);
        // left
        if(dir==2 )  dfs(grid, row, col, i, j - 1,2);
        // up
        if(dir==3 )  dfs(grid, row, col, i - 1, j,3);
        // down
        if(dir==4 )  dfs(grid, row, col, i + 1, j,4);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        vector<vector<int>> grid(m, vector<int>(n, -1));

        // marking guard
        for (auto it : guards) {
            grid[it[0]][it[1]] = 0;
        }

        // marking wall

        for (auto it : walls) {
            grid[it[0]][it[1]] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    // right
                    dfs(grid, m, n, i, j + 1,1);
                    // left
                    dfs(grid, m, n, i, j - 1,2);
                    // up
                    dfs(grid, m, n, i - 1, j,3);
                    // down
                    dfs(grid, m, n, i + 1, j,4);
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1)
                    cnt++;
            }
        }

        return cnt;
    }
};