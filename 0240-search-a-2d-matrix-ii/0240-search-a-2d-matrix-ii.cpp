class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int r=matrix.size();
        int c=matrix[0].size();
      for(int i=0;i<r;i++){
        if(target>=matrix[i][0] && target<=matrix[i][c-1]){
            int lo=0,hi=c-1;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                if(matrix[i][mid]==target) return true;
                else if(matrix[i][mid]>target) hi=mid-1;
                else lo=mid+1;
            }
        }
      }
        return false;
    }
};