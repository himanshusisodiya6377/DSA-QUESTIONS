class Solution {
public:

    int numTeams(vector<int>& rating) {

        int n = rating.size();

        int ans = 0;

        for (int j = 0; j < n; j++) {

            int smallerLeft = 0;
            int largerLeft = 0;

            int smallerRight = 0;
            int largerRight = 0;

            // Left side
            for (int i = 0; i < j; i++) {

                if (rating[i] < rating[j]) {
                    smallerLeft++;
                }
                else if (rating[i] > rating[j]) {
                    largerLeft++;
                }
            }

            // Right side
            for (int k = j + 1; k < n; k++) {

                if (rating[k] > rating[j]) {
                    largerRight++;
                }
                else if (rating[k] < rating[j]) {
                    smallerRight++;
                }
            }

            ans += (smallerLeft * largerRight);

            ans += (largerLeft * smallerRight);
        }

        return ans;
    }
};