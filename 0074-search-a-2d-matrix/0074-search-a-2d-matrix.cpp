class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();//rows
        int m=matrix[0].size();//coloumn
        for(int i=0;i<n;i++){
            int lo=matrix[i][0],hi=matrix[i][m-1];
            if(hi==target) return true;
            else if(lo==target) return true;
           else if(lo<target && hi>target){
                lo=0,hi=m-1;
                while(lo<=hi){
                int mid=lo+((hi-lo)/2);
                if(matrix[i][mid]==target) return true;
                else if(matrix[i][mid]>target) hi=mid-1;
                else lo=mid+1;
                }
            }
        }
        return false;
    }
};