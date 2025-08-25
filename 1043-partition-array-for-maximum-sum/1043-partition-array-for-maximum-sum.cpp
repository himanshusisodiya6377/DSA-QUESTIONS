class Solution {
public:

    int maxi(int i,int j,vector<int>&arr){
        int maxii=INT_MIN;
        for(int k=i;k<=j;k++){
            maxii=max(maxii,arr[k]);
        }
        return maxii;
    }

    int solve(int i,int j,vector<int>&arr,int ran,vector<vector<int>>&dp){
        // if(j-i+1>ran) return 0;

        if(i>j) return 0;
        if(i==j) return arr[i];

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=INT_MIN;
        for(int k=i;k<i+ran && k<arr.size();k++){
            int maxii=maxi(i,k,arr);
            int sum=maxii*(k-i+1)+solve(k+1,j,arr,ran,dp);
            ans=max(ans,sum);
        }
          
        if(ans==INT_MIN) return  dp[i][j]=0;

        return  dp[i][j]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        int ans=INT_MIN;
        for(int i=0;i<k && i<arr.size();i++){
            int maxii=maxi(0,i,arr);
            int sum=maxii*(i+1)+solve(i+1,n-1,arr,k,dp);
            ans=max(ans,sum);
        }
       
        if(ans==INT_MIN) return 0;
        return ans;
    }
};