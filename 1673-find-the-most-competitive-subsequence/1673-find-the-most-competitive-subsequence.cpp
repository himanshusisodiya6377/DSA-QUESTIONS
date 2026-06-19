class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int needToRemove = nums.size() - k;
        for (auto i : nums) {
            while (!ans.empty() && needToRemove > 0 && ans.back() > i) {
                ans.pop_back();
                needToRemove--;
            }
            ans.push_back(i);
        }
        while (needToRemove--) ans.pop_back();
        return ans;
    }
};