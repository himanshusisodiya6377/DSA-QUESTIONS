class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
         vector<int>v(n+1,0);
         int sum;
         for(int i=0;i<bookings.size();i++){
            sum=bookings[i][2];
            int fir=bookings[i][0];
            int last=bookings[i][1];
            v[fir-1]+=sum;
            v[last]-=sum;
         }
         for(int i=1;i<n;i++){
          v[i]+=v[i-1];
         }
         vector<int>ans;
         for(int i=0;i<n;i++) ans.push_back(v[i]);
         return ans;
    }
};