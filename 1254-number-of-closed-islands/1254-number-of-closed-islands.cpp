class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&visit,int r,int c,int row,int col){
        if(row<0 || row==r || col<0 || col==c || visit[row][col]==true || grid[row][col]==1) return;
        visit[row][col]=true;
        dfs(grid,visit,r,c,row+1,col);
        dfs(grid,visit,r,c,row-1,col);
        dfs(grid,visit,r,c,row,col-1);
        dfs(grid,visit,r,c,row,col+1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>>visit(r,vector<bool>(c,false));
        int ans=0;
        for(int i=0;i<r;i++){
        if(i==0 || i==r-1){
              for(int j=0;j<c;j++){
              if(grid[i][j]==0 && visit[i][j]==false){
                 dfs(grid,visit,r,c,i,j);
              }
              }
        }
        else{
             if(grid[i][0]==0 && visit[i][0]==false){
                 dfs(grid,visit,r,c,i,0);
              }
             if(grid[i][c-1]==0 && visit[i][c-1]==false){
                 dfs(grid,visit,r,c,i,c-1);
              }
        }
            
        }
        for(int i=1;i<r-1;i++){
            for(int j=1;j<c-1;j++){
                if(grid[i][j]==0 && visit[i][j]==false){
                    ans++;
                    dfs(grid,visit,r,c,i,j);
                }
            }
        }
        return ans;
    }
};