class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<vector<int>> q;   // {row, col, distance}
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        q.push({0, 0, 1});
        vis[0][0] = true;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur[0];
            int c = cur[1];
            int dis = cur[2];

            if (r == n - 1 && c == n - 1)
                return dis;

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    !vis[nr][nc] && grid[nr][nc] == 0) {

                    vis[nr][nc] = true;
                    q.push({nr, nc, dis + 1});
                }
            }
        }

        return -1;
    }
};