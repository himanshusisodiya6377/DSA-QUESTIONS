class Solution {
public:
    long long solve(int n, unordered_set<int>& st) {
        long long mini = n;

        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if(st.count(i)) mini=min(mini,i);

                if (i != n / i && st.count(n/i)) mini=min(mini,n/i);
            }
        }
        // cout<<mini<<endl;

        return mini;
    }
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        sort(nums.begin(), nums.end());
        unordered_set<int> st;

        for (auto& it : nums)
            st.insert(it);

        for (int i = 0; i < n; i++) {
            ans += solve(nums[i], st);
        }

        return ans;
    }
};