class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int r=mat.size();
        int sum=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<r;j++){
                if(i==j || j==r-i-1) sum+=mat[i][j];
            }
        }
        // if(r%2==0) return sum;
        // else sum-=mat[r/2][r/2];
        return sum;
    }
};