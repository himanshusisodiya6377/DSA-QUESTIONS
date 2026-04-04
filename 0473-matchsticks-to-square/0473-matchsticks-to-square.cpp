class Solution {
public:
    bool func(vector<int>& matchsticks, long long target,
              long long s1, long long s2, long long s3, long long s4,
              int idx) {

        if (idx == matchsticks.size()) {
            return (s1 == target && s2 == target && s3 == target && s4 == target);
        }

        int val = matchsticks[idx];

        // try s1
        if (s1 + val <= target) {
            if (func(matchsticks, target, s1 + val, s2, s3, s4, idx+1))
                return true;
        }

        // avoid duplicate
        if (s2 + val <= target) {
            if (func(matchsticks, target, s1, s2 + val, s3, s4, idx+1))
                return true;
        }

        if (s3 + val <= target) {
            if (func(matchsticks, target, s1, s2, s3 + val, s4, idx+1))
                return true;
        }

        if (s4 + val <= target) {
            if (func(matchsticks, target, s1, s2, s3, s4 + val, idx+1))
                return true;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        long long sum = 0;
        for (int x : matchsticks) sum += x;

        if (sum % 4 != 0) return false;

        sort(matchsticks.rbegin(), matchsticks.rend()); // 🔥 MUST

        return func(matchsticks, sum/4, 0, 0, 0, 0, 0);
    }
};