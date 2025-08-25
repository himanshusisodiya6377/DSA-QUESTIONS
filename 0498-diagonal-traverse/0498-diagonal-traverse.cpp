class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        map<int, vector<int>> mp;
        // traverse coloumn wise
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        int k = 0;
        for (auto v : mp) {

            if (k % 2 == 0)
                reverse(begin(v.second), end(v.second));
            k++;
            for (auto m : v.second) {
                ans.push_back(m);
            }
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};