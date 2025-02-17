class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count=0;//to avoid overflow condition 
        vector<vector<int>>v(n,vector<int>(n,0));
           int r=n; //rows
           int c=n; //coloumn
           int num=r*c;
           int left=0,top=0,bottom=r-1,right=c-1;
           int val=1;
          // int count =0;
   while((left<=right) && (top<=bottom)){
    
    for(int i=left;i<=right && count<num;i++){
       v[top][i]=val;
       val++;
        count++;
    }
    top++;
     for(int i=top;i<=bottom && count<num;i++){
        v[i][right]=val;
        val++;
        count++;
    }
    right--;
     for(int i=right;i>=left && count<num;i--){
        v[bottom][i]=val;
        val++;
        count++;
    }
    bottom--;
     for(int i=bottom;i>=top && count<num;i--){
        v[i][left]=val;
        val++;
        count++;
    }
    left++;
} 
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(v[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};