class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        bool flagrow=false;
        bool flagcol=false;
        int idxcol=-1;
        int idxrow=-1;
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        if(obstacleGrid[0][0]==1) return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
             if(obstacleGrid[i][j]==1) {
                idxcol=j;
                idxrow=i;
                continue;
             }
             if(idxrow==i) continue;
             if(idxcol==j) continue;
             if(i==0 || j==0) t[i][j]=1;
             if(i==0 && j==0) t[i][j]=1;
             
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    t[i][j]=0;
                    continue;
                }
                else t[i][j]=t[i-1][j]+t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
};