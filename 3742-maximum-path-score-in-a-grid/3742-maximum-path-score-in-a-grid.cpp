class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,int r_max,int c_max,int limit,int cost,vector<vector<vector<int>>>&dp){
        if(cost>limit || i<0 || j<0 || i>=r_max || j>=c_max) return INT_MIN;
 
        if(dp[i][j][cost]!=-1) return dp[i][j][cost];

        int addscore=grid[i][j];
        int addcost=grid[i][j]==0 ? 0 : 1;

        int newcost=addcost+cost;
        if(newcost>limit) return dp[i][j][cost]=INT_MIN;
        
        if(i==r_max-1 && j==c_max-1) return dp[i][j][cost]=addscore;

       int right=solve(grid,i,j+1,r_max,c_max,limit,newcost,dp);
       int down=solve(grid,i+1,j,r_max,c_max,limit,newcost,dp);
       int best=max(right,down);

       if(best==INT_MIN) return dp[i][j][cost]=INT_MIN;

       return dp[i][j][cost]=addscore+best;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();
        int cost=0;
        vector<vector<vector<int>>> dp(r + 1,vector<vector<int>>(c + 1, vector<int>(k + 1, -1)));
        int ans=solve(grid,0,0,r,c,k,cost,dp);
        if(ans==INT_MIN) return -1;
        return ans;
    }
};