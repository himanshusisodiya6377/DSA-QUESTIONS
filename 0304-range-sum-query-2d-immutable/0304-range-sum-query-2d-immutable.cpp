class NumMatrix {
public:
    vector<vector<int>>pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            vector<int>v(c,0);
            v[0]=matrix[i][0];
            for(int j=1;j<c;j++){
              v[j]+=(v[j-1]+matrix[i][j]);
            }
            pre.push_back(v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        if(col1==0){
            for(int i=row1;i<=row2;i++){
            // sum+=(pre[i][col2]-pre[i][col1-1]);
            sum+=pre[i][col2];
            }
        }
        else{
            for(int i=row1;i<=row2;i++){
            sum+=(pre[i][col2]-pre[i][col1-1]);
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */