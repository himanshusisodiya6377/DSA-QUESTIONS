class Solution {
public:

    int solve(vector<int>&prices, vector<vector<vector<int>>>&dp,int index,int holding,int transaction){

       if(index>=prices.size() || transaction==0) return 0;
 
        int profit=0;

        if(holding==0){
            profit=max(solve(prices,dp,index+1,0,transaction),solve(prices,dp,index+1,1,transaction)-prices[index]);
        }
        else profit=max(solve(prices,dp,index+1,1,transaction),solve(prices,dp,index+1,0,transaction-1)+prices[index]);
       
        return profit;

    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,dp,0,0,2);
    }
};