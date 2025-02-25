class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        double r = cust.size();
        if(r==1) return cust[0][1];
        double ans = cust[0][1];
        double time = cust[0][0] + cust[0][1];
        for (int i = 1; i < r; i++) {
            if (cust[i][0] < time) {
                double x = time + cust[i][1] - cust[i][0];
                ans += x;

                time += cust[i][1];

            } else {
                ans += cust[i][1];
                time = cust[i][0] + cust[i][1];
            }
        }
        return ans / r;
    }
};