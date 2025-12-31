class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.top()] >= nums[i])
                st.push(i);
        }

        int len = 0;

        int j = n - 1;

        while (!st.empty() && j >= 0) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                len = max(len, j - st.top());
                st.pop();
            }
            j--;
        }
        return len;
    }
};