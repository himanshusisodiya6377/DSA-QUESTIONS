class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2 && k == 1) {
            if (nums[0] != nums[1])
                return max(nums[0],nums[1]);
        }
        if (n == 2 && k == 2) {
            if (nums[0] != nums[1])
                return nums[0] + nums[1];
        }
        unordered_map<int, int> mp;
        long long sum1=0;
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
            sum1+=nums[i];
        }
        long long maxi = 0;
        if (mp.size() == k) {
            maxi=sum1;
        }
        long long i = 0, j = k - 1;
        while (j < n-1) {
            i++;
            if (j < n)
                j++;
            mp[nums[j]]++;
            mp[nums[i - 1]]--;
            if (mp[nums[i - 1]] == 0)
                mp.erase(nums[i - 1]);
                  sum1+=nums[j];
                sum1-=nums[i-1];
            if (mp.size() == k) {
                maxi=max(maxi,sum1);
            }
        }
        return maxi;
    }
};