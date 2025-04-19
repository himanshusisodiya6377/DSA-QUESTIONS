class Solution {
public:
    int memorization(int i,int j,int m,int n,vector<vector<int>>&t){
        if(i==m-1 && j==n-1) return 1;
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(t[i][j]!=-1) return t[i][j];
        return t[i][j]=memorization(i,j+1,m,n,t)+memorization(i+1,j,m,n,t);
    }
    int uniquePaths(int m, int n) {
       int i=0,j=0;
       vector<vector<int>>t(m+1,vector<int>(n+1,-1));
       return memorization(i,j,m,n,t);
    }
};