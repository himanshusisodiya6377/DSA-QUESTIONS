class Solution {
public:
    int median(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();

        int lo = INT_MAX, hi = INT_MIN;

        for (int i = 0; i < r; i++) {
            lo = min(lo, mat[i][0]);
            hi = max(hi, mat[i][c - 1]);
        }

        int desired = (r * c) / 2;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;

            for (int i = 0; i < r; i++) {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (cnt <= desired)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return lo;
    }
};
