class Solution {
public:
    void toggle_row(vector<vector<int>>& grid,int row){
        for(int j=0;j<grid[0].size();j++){
            if(grid[row][j]==1) grid[row][j]=0;
            else grid[row][j]=1;
        }
    }
    void toggle_col(vector<vector<int>>&grid,int col){
        for(int i=0;i<grid.size();i++){
            if(grid[i][col]==1) grid[i][col]=0;
            else grid[i][col]=1;
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
         //working on row

         for(int i=0;i<r;i++){
            if(grid[i][0]==0){
                toggle_row(grid,i);
            }
         }

        //   for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        //  }

         vector<int>col_sum(c,0);
         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) col_sum[j]++;
            }
         }

        //  for(auto it : col_sum) cout<<it<<" ";

         for(int j=0;j<c;j++){
            int num_zero=r-col_sum[j];
            if(num_zero>col_sum[j]){
                toggle_col(grid,j);
            }
         }

        //       for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        //  }

         int ans=0;
         for(int i=0;i<r;i++){
            //   int p=pow(2,c-1);
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                   int p=pow(2,c-1-j);
                    ans+=p;
                }
            }
         }

         return ans;
    }
};