class Solution {
public:

    int solve(int index,int holding,vector<vector<int>>&dp,vector<int>&prices){

        if(index>=prices.size()) return 0;

        if(dp[index][holding]!=-1) return dp[index][holding];

        int pro=0;

        if(holding==1){

            int sell=prices[index]+solve(index+2,0,dp,prices);
            int hold=solve(index+1,1,dp,prices);

            pro=max(sell,hold);

        }
        else{

            int buy=-prices[index]+solve(index+1,1,dp,prices);

            int hold=solve(index+1,0,dp,prices);

            pro=max(buy,hold);


        }

        return dp[index][holding]=pro;

    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,0,dp,prices);
    }
};