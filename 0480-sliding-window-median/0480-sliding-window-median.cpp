class Solution {
public:
    multiset<int> low, high; // low: smaller half, high: larger half
    void rebalance() {
        while (low.size() > high.size() + 1) {
            high.insert(*prev(low.end()));
            low.erase(prev(low.end()));
        }
        while (low.size() < high.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {

            // 1️⃣ insert
            if (low.empty() || nums[i] <= *prev(low.end()))
                low.insert(nums[i]);
            else
                high.insert(nums[i]);

            rebalance();

            // 2️⃣ remove element leaving window
            if (i >= k) {
                if (low.find(nums[i - k]) != low.end())
                    low.erase(low.find(nums[i - k]));
                else
                    high.erase(high.find(nums[i - k]));

                rebalance();
            }

            // 3️⃣ take median
            if (i >= k - 1) {
                if (k % 2 == 1)
                    ans.push_back(*prev(low.end()));
                else
                    ans.push_back(((double)*prev(low.end()) + *high.begin()) /
                                  2.0);
            }
        }
        return ans;
    }
};
