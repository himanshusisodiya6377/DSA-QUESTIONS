class Solution {
public:
    // unordered_map<int,int>mp;
    int mod = 1e9 + 7;
    int solve(int x) {
        if (x <= 0)
            return 1;
        long long sum = (1LL * x * (x + 1)) % mod;
        long long inv2 = (mod + 1) / 2;   // for mod = 1e9+7
        sum = (sum * inv2) % mod;

        return (sum * solve(x - 2)) % mod;
    }
    int countOrders(int n) { return solve(2 * n - 1) % mod; }
};