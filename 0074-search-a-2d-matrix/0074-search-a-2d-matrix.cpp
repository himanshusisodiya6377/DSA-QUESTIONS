class Solution {
public:
    int check(vector<vector<int>>matrix, int n,int r,int c){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(n==0) return matrix[i][j];
                    n--;
                }
            }
            return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int lo=0,hi=r*c;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int x=check(matrix,mid,r,c);
            if(x==target) return true;
            else if(x>target) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};