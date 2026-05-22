class Solution {
public:
    int mini=INT_MAX;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&grid,int r,int skip,int row,int col){
        if(r>=row) return 0;
        if(dp[r][skip]!=INT_MAX) return dp[r][skip];
        int min_=INT_MAX;
        for(int i=0;i<col;i++){
            if(i==skip) continue;
             min_=min(min_,grid[r][i]+solve(grid,r+1,i,row,col));
        }
        return dp[r][skip]= min_;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        dp.resize(r,vector<int>(c,INT_MAX));
        for(int i=0;i<c;i++){
            mini=min(mini,grid[0][i]+solve(grid,1,i,r,c));
        }
        return mini;
    }
};