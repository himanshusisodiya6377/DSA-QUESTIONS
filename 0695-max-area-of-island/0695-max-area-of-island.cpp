class Solution {
public:

    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&visit,int row,int col,int i,int j,int &ans){
        if(i<0 || j<0 || i>=row || j>=col || visit[i][j]==true || grid[i][j]==0) return;
        visit[i][j]=true;
        ans++;
        //right
        dfs(grid,visit,row,col,i,j+1,ans);
        //left
        dfs(grid,visit,row,col,i,j-1,ans);
        //up
        dfs(grid,visit,row,col,i-1,j,ans);
        //down
        dfs(grid,visit,row,col,i+1,j,ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int maxi=INT_MIN;
        vector<vector<bool>>visit(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && visit[i][j]==false){
                    int ans=0;
                    dfs(grid,visit,r,c,i,j,ans);
                    maxi=max(maxi,ans);
                }
            }
        }
        if(maxi==INT_MIN) maxi=0;
        return maxi;
    }
};