class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int i = n - 2;

        // Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        // If such an element exists
        if (i >= 0) {
            int j = n - 1;

            // Find the smallest element greater than nums[i]
            while (nums[j] <= nums[i])
                j--;

            swap(nums[i], nums[j]);
        }

        // Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};