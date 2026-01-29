class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {

        int n = nums.size();

        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        st.insert(0);

        vector<bool> ans(n, false);
        int idx = 0;
        // checking posibilities
        for (int i = 1; i <= n; i++) {
            // generating all sum
            while (idx < n && nums[idx] <= i) {
                vector<int> curr(st.begin(), st.end());
                for (int sum : curr) {
                    int new_val = sum + nums[idx];
                    if (new_val <= k)
                        st.insert(new_val);
                }
                idx++;
            }

            // if left me exist krta ho
            if (st.find(k) != st.end()) {
                ans[i - 1] = true;
            } else {
                // cout<<idx<<"idx"<<endl;
                for (int j = idx; j < n; j++) {
                    int len = j-idx+1;
                    int needed = i * len;
                    // cout<<needed<<k-needed<<endl;

                    if (st.find(k - needed) != st.end()) {
                        ans[i - 1] = true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};