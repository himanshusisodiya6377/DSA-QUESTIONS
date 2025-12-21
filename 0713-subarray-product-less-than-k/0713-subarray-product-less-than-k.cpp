class Solution {
public:
       int solve(vector<int>& nums, int k) {
        if (k <= 0) return 0;

        int i = 0;
        int j = 0;
        int count = 0;
        int sum = 1;

        while (j < nums.size()) {
            sum *=nums[j];   // count odd numbers

            while (sum > k) {
                sum /= (nums[i]);
                i++;
            }

            count += (j - i + 1);
            j++;
        }

        return count;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        return solve(nums,k-1);
    }
};