class Solution {
public:
    int mod = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        int n = queries.size();

        vector<int> ans(n, 0);

        vector<long long> power(m, 0);   // count of non-zero digits
        vector<long long> number(m, 0);  // concatenated non-zero digits
        vector<long long> prefix(m, 0);  // sum of non-zero digits
        vector<long long> pow10(m + 1, 1);

        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % mod;
        }

        prefix[0] = (s[0] != '0') ? s[0] - '0' : 0;
        number[0] = prefix[0];
        power[0] = (s[0] != '0');

        for (int i = 1; i < m; i++) {
            prefix[i] = prefix[i - 1];
            number[i] = number[i - 1];
            power[i] = power[i - 1];

            if (s[i] != '0') {
                int d = s[i] - '0';
                prefix[i] += d;
                number[i] = (number[i] * 10 + d) % mod;
                power[i]++;
            }
        }

        for (int i = 0; i < n; i++) {
            int lf = queries[i][0];
            int rg = queries[i][1];

            long long sum =
                prefix[rg] - (lf > 0 ? prefix[lf - 1] : 0);

            long long cnt =
                power[rg] - (lf > 0 ? power[lf - 1] : 0);

            long long x;
            if (lf == 0) {
                x = number[rg];
            } else {
                long long remove =
                    (number[lf - 1] * pow10[cnt]) % mod;
                x = (number[rg] - remove + mod) % mod;
            }

            ans[i] = (x * (sum % mod)) % mod;
        }

        return ans;
    }
};
