class Solution {
public:
    int dp[1001][1001][2][4];

    int solve(vector<int>& rating, int idx, int prevIdx, int trend, int count) {

        if (count == 3)
            return 1;

        if (idx >= rating.size())
            return 0;

        if (dp[idx][prevIdx + 1][trend][count] != -1) {
            return dp[idx][prevIdx + 1][trend][count];
        }

        int take = 0;

        // Increasing
        if (trend == 1) {

            if (prevIdx == -1 || rating[idx] > rating[prevIdx]) {

                take = solve(rating, idx + 1, idx, trend, count + 1);
            }
        }

        // Decreasing
        else {

            if (prevIdx == -1 || rating[idx] < rating[prevIdx]) {

                take = solve(rating, idx + 1, idx, trend, count + 1);
            }
        }

        int notTake = solve(rating, idx + 1, prevIdx, trend, count);

        return dp[idx][prevIdx + 1][trend][count] = take + notTake;
    }

    int numTeams(vector<int>& rating) {

        memset(dp, -1, sizeof(dp));

        int increasing = solve(rating, 0, -1, 1, 0);

        memset(dp, -1, sizeof(dp));

        int decreasing = solve(rating, 0, -1, 0, 0);

        return increasing + decreasing;
    }
};