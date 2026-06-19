class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid,
                                            vector<int>& pricing,
                                            vector<int>& start,
                                            int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<vector<int>> q;
        q.push({start[0], start[1], 0});
        vis[start[0]][start[1]] = 1;

        vector<vector<int>> items;

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            int x = cur[0];
            int y = cur[1];
            int dist = cur[2];

            if(grid[x][y] >= pricing[0] &&
               grid[x][y] <= pricing[1]) {
                items.push_back({dist, grid[x][y], x, y});
            }

            for(auto &d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                if(nx < 0 || nx >= m ||
                   ny < 0 || ny >= n ||
                   vis[nx][ny] ||
                   grid[nx][ny] == 0)
                    continue;

                vis[nx][ny] = 1;
                q.push({nx, ny, dist + 1});
            }
        }

        sort(items.begin(), items.end());

        vector<vector<int>> ans;

        for(int i = 0; i < min(k, (int)items.size()); i++) {
            ans.push_back({items[i][2], items[i][3]});
        }

        return ans;
    }
};