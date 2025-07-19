class Solution {
public:
   //memorization
   int climb(int n,vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=climb(n-1,dp)+climb(n-2,dp); 
   }
 
    int climbStairs(int n) {
    //    vector<int>dp(n+1,-1);
    //    return climb(n,dp);
    if(n==1) return 1;
     int prev=2,prev2=1;
    for(int i=3;i<=n;i++){
        int sum=prev+prev2;
        prev2=prev;
        prev=sum;
    }
    return prev;
    }
};