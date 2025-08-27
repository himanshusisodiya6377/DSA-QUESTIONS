class Solution {
public:
     
     int r,c;

     vector<vector<int>>dir={{1,1},{1,-1},{-1,-1},{-1,1}};

    int solve(int i,int j,int d,bool canTurn,vector<vector<int>>&grid,int num){

          int new_i=i+dir[d][0];
          int new_j=j+dir[d][1];

          if(new_i<0 || new_i>=grid.size() || new_j<0 || new_j>=grid[0].size() || grid[new_i][new_j]!=num) return 0;

          int result=0;

          int keeping=1+solve(new_i,new_j,d,canTurn,grid,(num==2 ? 0 : 2));
          result=max(result,keeping);

          int notHold=0;

          if(canTurn){
            notHold=1+solve(new_i,new_j,(d+1)%4,!canTurn,grid,(num==2 ? 0 : 2));
          }

          result=max(result,notHold);
          

          return result;

    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        
        r=grid.size();
        c=grid[0].size();
 
        int result=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                for(int d=0;d<=3;d++){
                    result=max(result,1+solve(i,j,d,true,grid,2));
                }
                }
            }
        }

        return result;

    }
};