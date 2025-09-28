class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int i = n - 1;
        while (i - 2 >= 0) {
            if (nums[i] >= (nums[i - 1] + nums[i - 2])) {
                i--;
            } else
                return (nums[i] + nums[i - 1] + nums[i - 2]);
        }
        return 0;
    }
};