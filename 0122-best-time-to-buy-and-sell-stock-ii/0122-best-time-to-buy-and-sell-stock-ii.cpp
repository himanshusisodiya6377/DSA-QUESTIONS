class Solution {
public:

    int profit(int index,int holding,vector<int>&prices,vector<vector<int>>&dp){
 
      if(index>=prices.size()) return 0;

      if(dp[index][holding]!=-1) return dp[index][holding];

      int pro=0;

      if(holding==1){
        
          int sell=prices[index]+profit(index+1,0,prices,dp);

          int hold=profit(index+1,1,prices,dp);

          pro=max(sell,hold);

      }
      else{

         int buy=profit(index+1,1,prices,dp)-prices[index];

         int hold=profit(index+1,0,prices,dp);

         pro=max(buy,hold);

      }

      return dp[index][holding]=pro;

    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,INT_MIN));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<prices.size();i++){
 
           dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);

           dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);

        }

        return dp[prices.size()-1][0];
    }
};