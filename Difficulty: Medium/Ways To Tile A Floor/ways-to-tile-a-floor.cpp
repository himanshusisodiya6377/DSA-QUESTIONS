class Solution {
  public:
    int solve(int i,int n,vector<int>&dp){
        if(i>n+1) return 0;
        if(dp[i]!=-1) return dp[i];
        if(i==n-1 || i==n) return 1;
        
        return dp[i]=solve(i+2,n,dp)+solve(i+1,n,dp);
    }
    int numberOfWays(int n) {
        // code here
        //do it + dont do it 
        vector<int>dp(n+1,-1);
        return solve(2,n,dp)+solve(1,n,dp);
    }
};