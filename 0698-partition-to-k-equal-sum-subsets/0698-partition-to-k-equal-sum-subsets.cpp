class Solution {
public:
//do it yaato raat  hi lo bahut important question he ye bhai jaan 
    bool solve(vector<int>& nums, vector<bool>& vis, int k, int currSum, int target, int start) {
        if (k == 1) return true;

        if (currSum == target)
            return solve(nums, vis, k - 1, 0, target, 0);

        for (int i = start; i < nums.size(); i++) {
            if (!vis[i] && currSum + nums[i] <= target) {
                vis[i] = true;

                if (solve(nums, vis, k, currSum + nums[i], target, i + 1))
                    return true;

                vis[i] = false;

                // 🔥 pruning
                if (currSum == 0) return false;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        vector<bool> vis(nums.size(), false);

        return solve(nums, vis, k, 0, target, 0);
    }
};