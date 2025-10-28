#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        vector<vector<bool>> visit(r, vector<bool>(c, false));
        queue<pair<int,int>> q;

        // Step 1: Push all 1’s into queue as starting points (distance = 0)
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visit[i][j] = true;
                    ans[i][j] = 0;
                }
            }
        }

        // Step 2: BFS expansion
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                // boundary + not visited
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};
