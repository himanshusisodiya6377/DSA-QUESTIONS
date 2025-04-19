class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0) t[i][j]=matrix[i][j];
                else if(j==0){
                    t[i][j]=matrix[i][j]+min(t[i-1][j],t[i-1][j+1]);
                }
                else if(j==n-1){
                    t[i][j]=matrix[i][j]+min(t[i-1][j],t[i-1][j-1]);
                }
                else{
                    int mini=min(t[i-1][j-1],t[i-1][j]);
                    mini=min(mini,t[i-1][j+1]);
                    t[i][j]=matrix[i][j]+mini;
                }
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(mini>t[m-1][i]) mini=t[m-1][i];
        }
        return mini;
    }
};