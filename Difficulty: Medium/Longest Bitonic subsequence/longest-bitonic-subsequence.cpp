
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {

        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // int maxi=1;

        vector<int>dp(n,1);
         
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        
        vector<int>dpb(n,1);
        
         for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i])
                dpb[i]=max(dpb[i],dpb[j]+1);
            }
        }
        
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(dp[i]!=0 && dpb[i]!=0 && dp[i]!=1 && dpb[i]!=1)
            maxi=max(maxi,dp[i]+dpb[i]);
        }
        
        if(maxi==INT_MIN) return 0;
        
        return maxi-1;
    }
};
