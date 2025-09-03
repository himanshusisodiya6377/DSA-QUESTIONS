class Solution {
public:

    int solve(vector<vector<int>>&grid,int row,int col,int i,int j,vector<vector<int>>&dp){
        if(i>=row || i<0 || j>=col || j<0) return INT_MAX;
        if(i==row-1 && j==col-1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=grid[i][j]+min(solve(grid,row,col,i,j+1,dp),solve(grid,row,col,i+1,j,dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(r==1 && c==1) return grid[0][0];
        vector<vector<int>>dp(r,vector<int>(c,-1));
        return grid[0][0]+min(solve(grid,r,c,0,1,dp),solve(grid,r,c,1,0,dp));
    }
};