class Solution {
public:

    bool isValidTurn(string old, string dir) {
    if (old=="lt") return (dir=="lt" || dir=="rt");
    if (old=="rt") return (dir=="rt" || dir=="br");
    if (old=="bl") return (dir=="bl" || dir=="lt");
    if (old=="br") return (dir=="br" || dir=="bl");
    return false;
}

    int solve(int i, int j, bool num,string old, string dir,int d, vector<vector<int>>& grid,vector<vector<bool>>&visit,vector<vector<int>>&dp) {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j]==1 || visit[i][j])
            return 0;
           

        //number swapping
        if (num && grid[i][j] != 2) return 0;
        if (!num && grid[i][j] != 0) return 0;

        //direction
        if(d>=2) return 0;

        //90 degree
        if (!isValidTurn(old, dir)) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        visit[i][j]=true;

        int ans = 0;

        int lt = 1+solve(i - 1, j - 1, !num,dir, "lt",(dir=="lt" ? d : d+1), grid,visit,dp);
        int rt = 1+solve(i - 1, j + 1, !num,dir, "rt",(dir=="rt" ? d : d+1), grid,visit,dp);
        int bl = 1+solve(i + 1, j - 1, !num,dir, "bl",(dir=="bl" ? d : d+1), grid,visit,dp);
        int br = 1+solve(i + 1, j + 1, !num,dir,  "br",(dir=="br" ? d : d+1), grid,visit,dp);

        visit[i][j]=false;

        ans = max(ans, max({lt, rt, bl, br}));

        return dp[i][j]=ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;

        vector<vector<bool>>visit(row,vector<bool>(col,false));
        vector<vector<int>>dp(row,vector<int>(col,-1));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    // true-->2
                    visit[i][j]=true;
                    int lt = 1+solve(i - 1, j - 1, true, "lt","lt",0, grid ,visit,dp);
                    int rt = 1+solve(i - 1, j + 1, true, "rt","rt",0, grid ,visit,dp);
                    int bl = 1+solve(i + 1, j - 1, true, "bl","bl",0, grid ,visit,dp);
                    int br = 1+solve(i + 1, j + 1, true, "br","br",0, grid ,visit,dp);
                    visit[i][j]=false;
                   ans = max(ans, max({lt, rt, bl, br}));
                }
            }
        }

        return ans;
    }
};