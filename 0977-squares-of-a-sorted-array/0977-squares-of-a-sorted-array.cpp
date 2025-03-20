class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] * nums[i];
            ans.push_back(x);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};