class Solution {
  public:
  
    void dfs(vector<vector<bool>>&visit,vector<vector<char>>&grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='X' || visit[i][j]) return;
        
        // cout<<"yes"<<endl;
        visit[i][j]=true;
        
        dfs(visit,grid,i,j+1);
        dfs(visit,grid,i,j-1);
        dfs(visit,grid,i+1,j);
        dfs(visit,grid,i-1,j);
        
    }
    void fill(vector<vector<char>>& grid) {
        // Code here
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>>visit(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // if((i==0 || i==r-1) && (j==0 || j==c-1) && !visit[i][j] && grid[i][j]=='O'){
                //     dfs(visit,grid,i,j);
                // }
                if((i==0 || i==r-1) && !visit[i][j] && grid[i][j]=='O') {
                    dfs(visit,grid,i,j);
                }
                else{
                    if((j==0 || j==c-1) && !visit[i][j] && grid[i][j]=='O'){
                        dfs(visit,grid,i,j);
                    }
                }
            }
        }
        
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<visit[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='O' && visit[i][j]==false){
                    grid[i][j]='X';
                }
            }
        }
        // return grid;
    }
};