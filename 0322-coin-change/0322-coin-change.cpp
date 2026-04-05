class Solution {
public:
    vector<vector<int>>dp;
     long long solve(vector<int>&coins,int idx,int amount){
        if(idx>=coins.size()){
            if(amount==0) return 0;
            return INT_MAX;
        }
        if(amount<0) return INT_MAX;
        if(amount==0) return 0;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
            // cout<<amount<<endl;
         long long ans=INT_MAX;
         long long maxi_use=amount/coins[idx];

        for(int i=0;i<=maxi_use;i++){
            long long res=(i)+solve(coins,idx+1,amount-((i)*coins[idx]));
            // if(res==INT_MAX+1) return INT_MAX;
            ans=min(ans,res);
        }

        return dp[idx][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(),coins.rend());
        dp.resize(coins.size()+1,vector<int>(amount+1,-1));
        int res=solve(coins,0,amount);
        return (res==INT_MAX ? -1 : res);
    }
};