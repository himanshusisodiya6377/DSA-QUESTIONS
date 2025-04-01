class Solution {
public:
    void dfs(vector<vector<int>>& land, vector<vector<bool>>& visit, int r,
             int c, int row, int col, vector<int>& v) {
        if (row < 0 || row == r || col < 0 || col == c ||
            visit[row][col] == true || land[row][col] == 0)
            return;
        visit[row][col] = true;
        v[2] = max(v[2], row);
        v[3] = max(v[3], col);
        // if(land[row][col]==0) return true;
        dfs(land, visit, r, c, row - 1, col, v);
        dfs(land, visit, r, c, row + 1, col, v);
        dfs(land, visit, r, c, row, col + 1, v);
        dfs(land, visit, r, c, row, col - 1, v);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int r = land.size();
        int c = land[0].size();
        vector<vector<bool>> visit(r, vector<bool>(c, false));
        vector<vector<int>> ans;
        for (int i = 0; i < r; i++) {

            for (int j = 0; j < c; j++) {
                if (land[i][j] == 1 && visit[i][j] == false) {
                    vector<int> v = {i, j, i, j};
                    dfs(land, visit, r, c, i, j, v);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};