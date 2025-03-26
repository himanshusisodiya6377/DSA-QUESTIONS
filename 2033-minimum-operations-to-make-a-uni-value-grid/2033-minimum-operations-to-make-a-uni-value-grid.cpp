class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int r = grid.size(); // rows
        int c = grid[0].size();
        vector<int> v;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                v.push_back(grid[i][j]);
            }
        }
        sort(begin(v), end(v));
        int mididx = (r * c) / 2;
        int medi = v[mididx];
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            if (medi % x != v[i] % x)
                return -1;
            ans += abs(medi - v[i]) / x;
        }
        return ans;
    }
};