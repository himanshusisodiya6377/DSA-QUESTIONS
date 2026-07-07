class Solution {
public:

    const long long MOD = 1000000007;

    vector<int> SPF() {

        const int N = 1000000;
        vector<int>spf(N+1);

        for(int i = 0; i <= N; i++) {
            spf[i] = i;
        }

        for(int i = 2; i*i <= N; i++) {

            if(spf[i] != i) continue;

            for (int j = i*i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }

        return spf;

    }

    int divisibleGame(vector<int>& nums) {

        // Don't forget to use static, else it will be recomputed everytime
        static vector<int>spf = SPF();

        // We will check if k is valid, and we want the minimum k first (also we want unique values)
        set<long long>st;

        for(auto elem : nums) {

            while(elem != 1) {
                st.insert(spf[elem]);
                elem /= spf[elem];
            }
        }

        long long maxScore = -1, minK = 2;

        for(auto& elem : st) {

            int k = elem;

            long long temp = 0;
            long long maxi = 0;

            for(auto& x : nums) {
                if(x % k == 0) temp += x;
                else temp -= x;

                if(temp < 0) temp = 0;
                maxi = max(maxi, temp);
            }

            if (maxi > maxScore) {
                maxScore = maxi;
                minK = k;
            }
        }

        long long ans = (maxScore * minK) % MOD;
        if(ans < 0) ans = (ans + MOD)%MOD;

        return ans;
    }
};