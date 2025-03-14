class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += candies[i];
            if (maxi < candies[i])
                maxi = candies[i];
        }
        int result = 0;
        if (sum < k)
            return 0;
        else {
            int lo = 1, hi = maxi;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                long long count = 0;
                for (int c : candies) {
                    count += c / mid;
                }
                if (count >= k) {
                    result = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return result;
    }
};