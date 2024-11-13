class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size(); //rows
        int c=matrix[0].size(); //coloumn
        int count=0;
        int num=r*c;
        vector<int>v;
           int left=0,top=0,bottom=r-1,right=c-1;
          // int count =0;
   while((left<=right) && (top<=bottom)){
    
    for(int i=left;i<=right && count<num;i++){
        v.push_back(matrix[top][i]);
        count++;
    }
    top++;
     for(int i=top;i<=bottom && count<num;i++){
        v.push_back(matrix[i][right]);
        count++;
    }
    right--;
     for(int i=right;i>=left && count<num;i--){
        v.push_back(matrix[bottom][i]);
        count++;
    }
    bottom--;
     for(int i=bottom;i>=top && count<num;i--){
        v.push_back(matrix[i][left]);
        count++;
    }
    left++;
}
        return v;
    }
};