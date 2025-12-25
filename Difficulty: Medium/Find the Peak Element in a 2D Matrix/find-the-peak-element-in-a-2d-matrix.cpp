class Solution {
  public:
    vector<int>solve(vector<vector<int>>&mat){
        int r=mat.size();
        int c=mat[0].size();
        int mini=INT_MIN;
        int lo=0,hi=c-1;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            int max_row=0;
            for(int i=1;i<r;i++){
                if(mat[i][mid]>mat[max_row][mid]) max_row=i;
            }
            
            int left=(mid>0) ? mat[max_row][mid-1] : mini;
            int right=(mid+1<c) ? mat[max_row][mid+1] : mini;
            
            if(mat[max_row][mid]>=left && mat[max_row][mid]>=right){
                return {max_row,mid};
            }
            
            else if(right > mat[max_row][mid]) lo=mid+1;
            else hi=mid-1;
        }
        return {-1,-1};
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
          int r=mat.size();
          int c=mat[0].size();
          return solve(mat);
    }
};
