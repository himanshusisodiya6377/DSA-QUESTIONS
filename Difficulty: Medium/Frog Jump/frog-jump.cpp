class Solution {
  public:
  
    int  Calc(int n,vector<int>&height,vector<int>&dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int left=Calc(n-1,height,dp)+abs(height[n]-height[n-1]);
        int right=INT_MAX;
        if(n>1) right=Calc(n-2,height,dp)+abs(height[n]-height[n-2]);
        return dp[n]=min(left,right);
    }
    
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,-1);
        return Calc(n-1,height,dp);
    }
};