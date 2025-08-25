class Solution {
public:

   int solve(int i,int j,vector<vector<char>>&matrix,vector<vector<int>>&dp){
    if(i>=matrix.size() || j>=matrix[0].size()) return 0;

    if(matrix[i][j]=='0') return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int right=solve(i,j+1,matrix,dp);
    int diagonal=solve(i+1,j+1,matrix,dp);
    int down=solve(i+1,j,matrix,dp);
    
    int side=1+min(right,min(diagonal,down));

    return dp[i][j]=side;
    
   }

    int maximalSquare(vector<vector<char>>& matrix) {
     int r=matrix.size();
     int c=matrix[0].size();
     int ans=0;

     vector<vector<int>>dp(r,vector<int>(c,-1));

     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]=='1'){
                ans=max(ans,solve(i,j,matrix,dp));
            }
        }
     }

     return ans*ans;   
    }
};