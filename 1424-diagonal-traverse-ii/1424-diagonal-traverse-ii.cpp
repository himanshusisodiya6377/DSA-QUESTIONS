class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> mp;
        int i = 0;
        for (auto v : nums) {
            for (int j = 0; j < v.size(); j++) {
                mp[i + j].push_back(v[j]);
            }
            i++;
        }
        vector<int> ans;
        for (auto v : mp) {
            reverse(begin(v.second), end(v.second));
            for (auto ele : v.second) {
                ans.push_back(ele);
            }
        }
        return ans;
    }
};