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
        vector<vector<int>>dp(prices.size(),vector<int>(2,INT_MIN));
        dp[0][0]=0;
        dp[0][1]=-prices[0]; 

        // bool flag=false;

        for(int i=1;i<prices.size();i++){
            
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);

            if (i >= 2)
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        else
            dp[i][1] = max(dp[i-1][1], -prices[i]);
            
    }
        
        return dp[prices.size()-1][0];
    }
};