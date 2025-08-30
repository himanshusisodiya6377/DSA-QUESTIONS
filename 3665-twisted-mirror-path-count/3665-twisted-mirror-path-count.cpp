class Solution {
public:

    // typedef long long lg;
    typedef long long lg;
     int MOD = 1e9+7;
    int dp[501][501][2];

    long long solve(long long i,long long j,long long row,long long col,int dir,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=row || j>=col) return 0;

        if(dp[i][j][dir]!=-1) return dp[i][j][dir];
        
        if(i==row-1 && j==col-1) return 1;


        long long ans;
        
        if(grid[i][j]==1){
            if(dir==1){
                long long down=solve(i+1,j,row,col,0,grid);
                ans=down;
            }
            else{
                long long right=solve(i,j+1,row,col,1,grid);
                ans=right;
            }
        }
        else{
            long long right=solve(i,j+1,row,col,1,grid);
        long long down=solve(i+1,j,row,col,0,grid);
            ans=(right+down)% MOD;
        }

        
        return dp[i][j][dir]=ans;
    }
    
    int uniquePaths(vector<vector<int>>& grid) {
        long long row=grid.size();
        long long col=grid[0].size();
        long long i=0,j=0;
        // long long cnt=0;

        memset(dp,-1,sizeof(dp));

        // vector<vector<vector<lg>>> dp(row, vector<vector<lg>>(col, vector<lg>(2, -1)));

        //0 -> right
        long long right=solve(i,j+1,row,col,1,grid);

        //1->down
        long long down=solve(i+1,j,row,col,0,grid);

        return (right+down)% MOD;
    }
};