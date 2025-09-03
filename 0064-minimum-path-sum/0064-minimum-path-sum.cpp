class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1) return grid[i][j];
        if(i>=m || j>=n)  return 1e9;//to remove invalid cases from observation
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(helper(grid,i+1,j,m,n,dp),helper(grid,i,j+1,m,n,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
     int m=grid.size();
     int n=grid[0].size();
     //bottom up
    //  vector<vector<int>>t(m,vector<int>(n,0));
    //  //intializatio
    //  t[0][0]=grid[0][0];
    //  for(int i=1;i<n;i++){
    //     t[0][i]=grid[0][i]+t[0][i-1];
    //  }   
    //   for(int i=1;i<m;i++){
    //     t[i][0]=grid[i][0]+t[i-1][0];
    //  } 
     

    //  for(int i=1;i<m;i++){
    //     for(int j=1;j<n;j++){
    //         t[i][j]=grid[i][j]+min(t[i-1][j],t[i][j-1]);
    //     }
    //  }
    // return t[m-1][n-1];

    //recursive
    int i=0,j=0;
    vector<vector<int>>dp(m,vector<int>(n,-1));
      return helper(grid,i,j,m,n,dp);
    }
};