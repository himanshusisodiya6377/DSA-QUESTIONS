class Solution {
public:
 
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>&v,int row,int col,int i,int j,int &ans){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]==0){
            ans++;
            return;
        }
        if(v[i][j]==true) return;
        v[i][j]=true;
        //right
        dfs(grid,v,row,col,i,j+1,ans);
        //left
        dfs(grid,v,row,col,i,j-1,ans);
        //up
        dfs(grid,v,row,col,i-1,j,ans);
        //down
        dfs(grid,v,row,col,i+1,j,ans);
    }
  
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        vector<vector<bool>>v(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    dfs(grid,v,r,c,i,j,ans);
                    break;
                }
            }
        }
        return ans;
    }
};