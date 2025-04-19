class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //memorization and recursive solution is easy to undersatnd
        //try to understand tabulation approach
        int m=triangle.size();
        vector<vector<int>>t(m);
        
        for (int i = 0; i < m; i++) {
            t[i].resize(triangle[i].size());
        }
        
        t[0][0]=triangle[0][0];
        //intialization
        for(int i=0;i<m;i++){
            for(int j=0;j<i+1;j++){
                if(j==0 && i!=0){
                    t[i][j]=triangle[i][j]+t[i-1][j];
                } 
                if(i==j && i!=0){
                    t[i][j]=triangle[i][j]+t[i-1][j-1];
                }
            }
        }
        for(int i=2;i<m;i++){
            for(int j=1;j<i;j++){
                t[i][j]=triangle[i][j]+min(t[i-1][j-1],t[i-1][j]);
            }
        }
        
        int mini = INT_MAX;
        for (int val : t[m - 1]) {
            mini = min(mini, val);
        }

        return mini;
    }
};