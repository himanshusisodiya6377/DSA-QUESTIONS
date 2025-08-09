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
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return profit(0,0,prices,dp);
    }
};