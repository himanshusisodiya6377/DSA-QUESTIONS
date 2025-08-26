class Solution {
public:

    int solve(int start,int end,vector<int>&nums,vector<int>&dp){
        
        if(start>end) return 0;

        if(start==end) return nums[start];

        if(dp[start]!=-1) return dp[start];

        int take=nums[start]+solve(start+2,end,nums,dp);

        int nottake=solve(start+1,end,nums,dp);

        return dp[start]=max(take,nottake);

    } 

    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];

        vector<int>dp1(n,-1);
        
        int sum1=solve(0,n-2,nums,dp1);

        vector<int>dp2(n,-1);

        int sum2=solve(1,n-1,nums,dp2);

        return max(sum1,sum2);
    }
};