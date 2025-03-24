class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int k = n - 1;
        int t = 0;
        for (int i = 0; i < n; i++) {
            t ^= nums[i];
            int doit = 0;
            // for (int i = 0; i < maximumBit; i++) {
            //     int temp = 1 << i;
            //     int check = (t & temp);
            //     if (check == 0) {
            //         doit = doit | (1 << i);
            //     }
            // }
            int temp=pow(2,maximumBit)-1;
            doit=t^temp;
            ans[k] = doit;
            k--;
        }
        return ans;
    }
};