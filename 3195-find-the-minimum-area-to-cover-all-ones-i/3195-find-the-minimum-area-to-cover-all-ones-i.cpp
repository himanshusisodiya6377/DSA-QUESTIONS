class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
       int row=grid.size();
       int col=grid[0].size();

       vector<bool>c(col,false);
       vector<bool>r(row,false);

       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==true){
                r[i]=true;
                c[j]=true;
            }
        }
       }

       int i=0,j=row-1;
       while(i<row && r[i]==false) i++;
       while(j>=0 && r[j]==false) j--;
       
       int len1;
       if(i<=j) len1=j-i+1;

       i=0;j=col-1;
       while(i<col && c[i]==false) i++;
       while(j>=0 && c[j]==false) j--;

       int len2;

       if(i<=j) len2=j-i+1;

       return len1*len2;
    }
};