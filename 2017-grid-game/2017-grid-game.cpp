class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        int n = grid[0].size();

        long long topSum = 0;

        for (int x : grid[0])
            topSum += x;

        long long bottomSum = 0;

        long long ans = LLONG_MAX;

        for (int j = 0; j < n; j++) {

            topSum -= grid[0][j];

            long long secondRobot = max(topSum, bottomSum);

            ans = min(ans, secondRobot);

            bottomSum += grid[1][j];
        }

        return ans;
    }
};