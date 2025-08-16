class Solution {
public:

    int solve(int idx,int prev_idx,vector<int>&nums,vector<vector<int>>&dp){

         if(idx>=nums.size()) return 0;
       
         if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];

         int len;
         len=0+solve(idx+1,prev_idx,nums,dp);

         if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            len=max(len,1+solve(idx+1,idx,nums,dp));
         }

         return dp[idx][prev_idx+1]=len;

    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int maxi=1;

        vector<int>dp(n,1);
         
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                dp[i]=max(dp[i],dp[j]+1);
            }
        }

        for(auto it : dp){
            maxi=max(maxi,it);
        }

        // return solve(0,-1,nums,dp);

        return maxi;
    }
};