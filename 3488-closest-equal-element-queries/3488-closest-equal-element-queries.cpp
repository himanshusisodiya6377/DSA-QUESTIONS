class Solution {
public:
 // i am anble to come up with approach but not able to code as pointer movement makes me confuse
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        vector<int> ans(queries.size(), -1);

        for (int i = 0; i < queries.size(); i++) {

            int idx = queries[i];
            int val = nums[idx];

            // ***** CORRECTION 1 *****
            // If this value occurs only once, answer is always -1.
            if (mp[val].size() == 1) {
                ans[i] = -1;
                continue;
            }

            int pos = lower_bound(mp[val].begin(), mp[val].end(), idx) - mp[val].begin();

            int curr = mp[val][pos];

            // ***** CORRECTION 2 *****
            // Wrap around to first occurrence if current is the last one.
            int next = (pos + 1 == mp[val].size())
                           ? mp[val][0]
                           : mp[val][pos + 1];

            // ***** CORRECTION 3 *****
            // Wrap around to last occurrence if current is the first one.
            int prev = (pos == 0)
                           ? mp[val].back()
                           : mp[val][pos - 1];

            // ***** CORRECTION 4 (MOST IMPORTANT) *****
            // Don't use:
            // min(next-curr, n-next+curr)
            // It fails when next < curr (wrap-around).
            //
            // Correct circular distance:
            int distNext = (next - curr + n) % n;

            // ***** CORRECTION 5 *****
            // Same for previous direction.
            int distPrev = (curr - prev + n) % n;

            // ***** CORRECTION 6 *****
            ans[i] = min(distNext, distPrev);
        }

        return ans;
    }
};