class Solution {
public:
    vector<vector<int>> dp;

    int solve(int left, int right, vector<int>& cuts) {

        if (right - left == 1)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int ans = INT_MAX;

        for (int i = left + 1; i < right; i++) {

            ans = min(ans,
                      solve(left, i, cuts)
                    + solve(i, right, cuts)
                    + cuts[right] - cuts[left]);
        }

        return dp[left][right] = ans;
    }

    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        dp.assign(m, vector<int>(m, -1));

        return solve(0, m - 1, cuts);
    }
};