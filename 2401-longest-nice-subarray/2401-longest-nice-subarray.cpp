class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int result = 0;
        int mask = 0;
        while (j < n) {
            while ((mask & nums[j]) != 0) {
                mask=(mask^ nums[i]);
                i++;
            }
            result = max(result, j - i + 1);
            mask |= nums[j];
            j++;
        }
        return result;
    }
};