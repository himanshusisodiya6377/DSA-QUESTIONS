class Solution {
public:
void bfs(vector<vector<int>>& grid,vector<vector<bool>>&visit,int r,int c,int row,int col,int &ans){
        if(row<0 || row==r || col<0 || col==c || visit[row][col]==true || grid[row][col]==0) return;
        visit[row][col]=true;
        bfs(grid,visit,r,c,row+1,col,ans);
        bfs(grid,visit,r,c,row-1,col,ans);
        bfs(grid,visit,r,c,row,col-1,ans);
        bfs(grid,visit,r,c,row,col+1,ans);
    }
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&visit,int r,int c,int row,int col,int &ans){
        if(row<0 || row==r || col<0 || col==c || visit[row][col]==true || grid[row][col]==0) return;
        visit[row][col]=true;
        ans++;
        dfs(grid,visit,r,c,row+1,col,ans);
        dfs(grid,visit,r,c,row-1,col,ans);
        dfs(grid,visit,r,c,row,col-1,ans);
        dfs(grid,visit,r,c,row,col+1,ans);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>>visit(r,vector<bool>(c,false));
        int ans=0;
        for(int i=0;i<r;i++){
        if(i==0 || i==r-1){
              for(int j=0;j<c;j++){
              if(grid[i][j]==1 && visit[i][j]==false){
                 bfs(grid,visit,r,c,i,j,ans);
              }
              }
        }
        else{
             if(grid[i][0]==1 && visit[i][0]==false){
                 bfs(grid,visit,r,c,i,0,ans);
              }
             if(grid[i][c-1]==1 && visit[i][c-1]==false){
                 bfs(grid,visit,r,c,i,c-1,ans);
              }
        }
            
        }
        for(int i=1;i<r-1;i++){
            for(int j=1;j<c-1;j++){
                if(grid[i][j]==1 && visit[i][j]==false){
                    dfs(grid,visit,r,c,i,j,ans);
                }
            }
        }
        return ans;
    }
};