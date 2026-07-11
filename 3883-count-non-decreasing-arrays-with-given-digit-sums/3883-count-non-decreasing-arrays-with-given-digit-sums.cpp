class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int MAX = 5000;

    int countArrays(vector<int>& digit) {

        int n = digit.size();

        // digitSum[s] -> all numbers having digit sum = s
        vector<int> digitSum(MAX + 1);

        for (int i = 0; i <= MAX; i++) {
            int x = i;
            int sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            digitSum[i] = sum;
        }

        // If any required digit sum is impossible
        for (int x : digit)
            if (x > 31)
                return 0;

        // next = dp for index+1
        vector<int> next(MAX + 1, 1);
        vector<int> cur(MAX + 1);

        // Process from last index to first
        for (int idx = n - 1; idx >= 0; idx--) {

            vector<int> suffix(MAX + 2, 0);

            // Build suffix sums
            for (int v = MAX; v >= 0; v--) {

                int ways = 0;

                if (digitSum[v] == digit[idx])
                    ways = next[v];

                suffix[v] = ways + suffix[v + 1];

                if (suffix[v] >= MOD)
                    suffix[v] -= MOD;
            }

            // dp[idx][prev] = suffix[prev]
            for (int v = 0; v <= MAX; v++)
                cur[v] = suffix[v];

            next = cur;
        }

        return next[0];
    }
};