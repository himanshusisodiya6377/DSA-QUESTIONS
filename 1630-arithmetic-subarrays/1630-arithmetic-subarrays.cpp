class Solution {
public:
    bool isA(vector<int> arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
            st.insert(arr[i]);
        }
        if (((maxi - mini) % (n - 1)) != 0)
            return false;
        int diff = (maxi - mini) / (n - 1);
        while (mini < maxi) {
            if (st.find(mini) == st.end())
                return false;
            mini += diff;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                          vector<int>& r) {
        int c = l.size();
        vector<bool> ans;
        for (int i = 0; i < c; i++) {
            vector<int> v(nums.begin() + l[i], nums.begin() + r[i] + 1);
            bool flag = isA(v);
            ans.push_back(flag);
        }

        return ans;
    }
};