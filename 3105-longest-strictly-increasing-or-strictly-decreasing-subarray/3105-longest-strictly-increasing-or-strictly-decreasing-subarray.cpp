class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        int count = 1;
        if (nums[0] < nums[1])
            flag = true;
        else
            flag = false;
        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            if (flag == true) {
                if (nums[i] < nums[i + 1]) {
                    count++;
                } else {
                    flag = false;
                    ans = max(count, ans);
                    count = 1;
                    if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
                        i--;
                }
            } else {
                if (nums[i] > nums[i + 1]) {
                    count++;
                } else {
                    flag = true;
                    ans = max(count, ans);
                    count = 1;
                    if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
                        i--;
                }
            }
        }
        ans = max(ans, count);
        return ans;
    }
};