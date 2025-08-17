class Solution {
  public:
  
   int solve(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
       
       if(i>=j) return 0;
       
       if(dp[i][j]!=-1) return dp[i][j];
       
       int mini=INT_MAX;
       
       for(int k=i;k<j;k++){
           int tempans=solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+(arr[i-1]*arr[j]*arr[k]);
           
           if(mini>tempans) mini=tempans;
       }
       
       return dp[i][j]=mini;
       
   }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        // int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return solve(arr,1,n-1,dp);
        
    }
};