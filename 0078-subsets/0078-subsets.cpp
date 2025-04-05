class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total_subset = pow(2, n);
        vector<vector<int>> ans;
        // TC-O(n*2^n); with help of bit masking as input size is small
        for (int i = 0; i < total_subset; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};