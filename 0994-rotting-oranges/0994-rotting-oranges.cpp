class Solution {
public:
//logic aa gya he but code nahi bn rha
    void bfs(vector<vector<int>>&grid,queue<pair<int,int>>&q,int &ans,int row,int col,int &rotten){
        while(!q.empty() && rotten>0){
            int n=q.size();
        for(int k=0;k<n;k++){
         pair<int,int>p=q.front();
         q.pop();
//         v[p.first][p.second]=true;
          int i=p.first;
          int j=p.second;
          //right
          if(i>=0 && (j+1)>=0 && i<row && (j+1)<col && grid[i][j+1]==1) {
            q.push({i,j+1});
            grid[i][j+1]=2;
            rotten--;
          };
          //left
           if(i>=0 && (j-1)>=0 && i<row && (j-1)<col && grid[i][j-1]==1) {
            q.push({i,j-1});
            grid[i][j-1]=2;
            rotten--;
           };
           //up
            if((i-1)>=0 && (j)>=0 && (i-1)<row && (j)<col && grid[i-1][j]==1) {
                q.push({i-1,j});
                grid[i-1][j]=2;
                rotten--;
            };
           //down
            if((i+1)>=0 && (j)>=0 && (i+1)<row && (j)<col && grid[i+1][j]==1) {
                q.push({i+1,j});
                rotten--;
                grid[i+1][j]=2;
            };
        }
        ans++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int>>q;
        int source=2;
        int r=grid.size();
        int c=grid[0].size();
        //vector<pair<int,int>>v;
        int n=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==source){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    n++;
                }
            }
        }
 //       int n=q.size(); 
      bfs(grid,q,ans,r,c,n);
      if(n>0) return -1;
      return ans;
        
    }
};