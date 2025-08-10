class Solution {
public:

     int solve(vector<int>&prices,int index,int holding,int fee,vector<vector<int>>&dp){


         if(index>=prices.size()) return 0;

        if(dp[index][holding]!=-1) return dp[index][holding];

         int profit=0;

         if(holding==0){
           profit=max(solve(prices,index+1,0,fee,dp),solve(prices,index+1,1,fee,dp)-prices[index]);
         }
         else profit=max(solve(prices,index+1,1,fee,dp),solve(prices,index+1,0,fee,dp)+prices[index]-fee);
 
       return dp[index][holding]=profit;

     }

     int maxProfit(vector<int>& prices, int fee) {
      vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
      int n=prices.size();
      return solve(prices,0,0,fee,dp);   
    }
};