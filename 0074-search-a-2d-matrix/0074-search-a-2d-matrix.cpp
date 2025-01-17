class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        // if(r==1 && c==1) return matrix[0][0]==target;
        int lo=0,hi=r*c-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
           int i=mid/c;
           int j=mid%c;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};