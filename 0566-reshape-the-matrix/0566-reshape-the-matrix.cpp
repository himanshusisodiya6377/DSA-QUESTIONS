class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row=mat.size();
        int col=mat[0].size();
        if(row*col!=r*c) return mat;
        vector<vector<int>>v(r,vector<int>(c,0));
        int m=0,n=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                v[m][n]=mat[i][j];
                n++;
                if(n==c){
                    n=0;
                    m++;
                }
            }
        }
        return v;
    }
};