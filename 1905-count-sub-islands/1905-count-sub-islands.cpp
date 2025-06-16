class Solution {
public:
  
    void dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2, vector<vector<bool>>&visit,int row,int col,int i,int j,bool &flag){
        if(i<0 || j<0 || i>=row || j>=col || grid2[i][j]==0 || visit[i][j]) return ;
        if(grid2[i][j]==1 && grid1[i][j]==1){
            visit[i][j]=true;
        }
        if(grid2[i][j]==1 && grid1[i][j]==0) {
            visit[i][j]=true;
            flag=false;
        }

        //right
        dfs(grid1,grid2,visit,row,col,i,j+1,flag);
        //left
        dfs(grid1,grid2,visit,row,col,i,j-1,flag);
        //up
        dfs(grid1,grid2,visit,row,col,i-1,j,flag);
        //down
        dfs(grid1,grid2,visit,row,col,i+1,j,flag);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r=grid1.size();
        int c=grid1[0].size();
        int ans=0;
        vector<vector<bool>>visit(r,(vector<bool>(c,false)));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid2[i][j]==1 && visit[i][j]==false){
                    bool flag=true;
                    dfs(grid1,grid2,visit,r,c,i,j,flag);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};