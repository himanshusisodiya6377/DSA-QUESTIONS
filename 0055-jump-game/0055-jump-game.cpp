class Solution {
public:

   bool solve(int idx,vector<int>&nums,vector<int>&dp){

      if(idx>=nums.size()) return false;

      if(idx==nums.size()-1) return true;

      if(dp[idx]!=-1) return dp[idx];

       for(int i=1;i<=nums[idx];i++){
         int new_idx=idx+i;
         if(solve(new_idx,nums,dp)) return dp[idx]=true;
      }

      return dp[idx]=false;

   }

    bool canJump(vector<int>& nums) {
      
      int n=nums.size();
      
      if(n==1) return true;

      vector<int>dp(n+1,-1);
    //   if(n==1 && nums[0]!=0) return false;

      int idx=0;
      

      for(int i=1;i<=nums[0];i++){
         int new_idx=idx+i;
          if(solve(new_idx,nums,dp)) return true;
      }

      return false;

    }
};