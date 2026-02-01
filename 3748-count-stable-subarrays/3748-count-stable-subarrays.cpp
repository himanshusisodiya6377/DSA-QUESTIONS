class Solution {
public:
    vector<long long> countStableSubarrays(
        vector<int>& nums,
        vector<vector<int>>& queries
    ) {
        int n = nums.size();

        // len[i] = length of longest non-decreasing subarray ending at i
        vector<long long> len(n);

        // start[i] = starting index of that subarray
        vector<int> start(n);

        // prefix sum of len[]
        vector<long long> prefLen(n);

        // Step 1: build len[] and start[]
        len[0] = 1;
        start[0] = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] <= nums[i]) {
                len[i] = len[i - 1] + 1;
                start[i] = start[i - 1];
            } else {
                len[i] = 1;
                start[i] = i;
            }
        }

        // Step 2: prefix sum of len[]
        prefLen[0] = len[0];
        for (int i = 1; i < n; i++) {
            prefLen[i] = prefLen[i - 1] + len[i];
        }

        // Step 3: process queries
        vector<long long> res;
        res.reserve(queries.size());

        for (auto &q : queries) {
            int L = q[0], R = q[1];

            // Base: sum of len[i] for i in [L, R]
            long long ans = prefLen[R] - (L ? prefLen[L - 1] : 0);

            // Find first index p in [L, R] with start[p] >= L
            int lo = L, hi = R, p = R + 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (start[mid] >= L) {
                    p = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            // Indices [L, p-1] are overcounted
            if (p > L) {
                long long cnt = p - L; // number of bad indices
                // subtract sum of (len[i] - (i-L+1)) for i in [L, p-1]
                // = sum(len[i]) - sum(1..cnt)
                long long sumLenBad =
                    prefLen[p - 1] - (L ? prefLen[L - 1] : 0);
                long long tri = cnt * (cnt + 1) / 2;
                ans -= (sumLenBad - tri);
            }

            res.push_back(ans);
        }

        return res;
    }
};
