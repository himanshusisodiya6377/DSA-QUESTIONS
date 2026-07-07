class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        // if (indexDiff <= 0 || valueDiff < 0) return false;

        set<long long> window; // ordered values in current index window

        for (int i = 0; i < nums.size(); ++i) {
            // Remove element that is now out of allowed index distance.
            if (i > indexDiff) {
                window.erase((long long)nums[i - indexDiff - 1]);
            }

            long long x = nums[i];
            long long low = x - (long long)valueDiff;
            long long high = x + (long long)valueDiff;

            // First value >= low
            auto it = window.lower_bound(low);

            // lower_bound only guarantees "not too small".
            // We still must ensure "not too large" (<= high).
            if (it != window.end() && *it <= high) {
                return true;
            }

            window.insert(x);
        }

        return false;
    }
};