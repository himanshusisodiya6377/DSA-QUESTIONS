class Solution {
  public:
    int check(vector<vector<int>>&mat,int mid){
        int n=mat.size();
        int count=0;
        int row=0,col=n-1;
        
        while(row<n && col>=0){
            if(mat[row][col]<=mid){
                count+=(col+1);
                row++;
            }
            else{
                col--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n=mat.size();
        int lo=mat[0][0];
        int hi=mat[n-1][n-1];
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mat,mid)<k) lo=mid+1;
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }
};
