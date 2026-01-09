class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre_small(n, -1), pre_great(n, -1), next_small(n, -1),
            next_great(n, -1);

        // pre_small
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if (!st.empty())
                pre_small[i] = st.top();
            st.push(i);
        }

        for (auto& it : pre_small)
            cout << it << " ";

        cout << endl;

        while (!st.empty())
            st.pop();

        // prev greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if (!st.empty())
                pre_great[i] = st.top();
            st.push(i);
        }

        for (auto& it : pre_great)
            cout << it << " ";
        cout << endl;

        while (!st.empty())
            st.pop();

        // next greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if (!st.empty())
                next_great[i] = st.top();
            st.push(i);
        }

        for (auto& it : next_great)
            cout << it << " ";
        cout << endl;

        while (!st.empty())
            st.pop();

        // next smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if (!st.empty())
                next_small[i] = st.top();
            st.push(i);
        }

        for (auto& it : next_small)
            cout << it << " ";

        long long maxi = 0, mini = 0;
        for (int i = 0; i < n; i++) {

            long long leftMin = (pre_small[i] == -1) ? i + 1 : i - pre_small[i];
            long long rightMin =
                (next_small[i] == -1) ? n - i : next_small[i] - i;
            mini += nums[i] * leftMin * rightMin;

            long long leftMax = (pre_great[i] == -1) ? i + 1 : i - pre_great[i];
            long long rightMax =
                (next_great[i] == -1) ? n - i : next_great[i] - i;
            maxi += nums[i] * leftMax * rightMax;
        }

        return maxi - mini;
        return 0;
    }
};