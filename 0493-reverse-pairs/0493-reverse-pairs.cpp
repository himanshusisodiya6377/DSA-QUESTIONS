class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<long long> st;
        int ans = 0;

        for (int i = nums.size() - 1; i >= 0; i--) {
            double target = (double)nums[i] / 2.0;

            ans += lower_bound(st.begin(), st.end(), target) -st.begin();
            st.insert(lower_bound(st.begin(), st.end(), nums[i]),nums[i]);
        }

        return ans;
    }
};