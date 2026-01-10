class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // base case fill
        // all i==0 and j==0 dp[i][j]=0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = s1[i-1] + dp[i - 1][j - 1];
                } else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }


        int ans=0;
        for(auto &it : s1) ans+=it;
        for(auto &it : s2) ans+=it;

       
        return ans - 2*dp[n][m];
    }
};