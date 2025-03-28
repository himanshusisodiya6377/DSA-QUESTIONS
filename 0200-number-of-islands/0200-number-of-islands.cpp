class Solution {
public:
     void  dfs(vector<vector<char>>& grid, char target,vector<vector<int>>&visited, int r, int c, int row, int col) {
        if (row < 0 || row == r || col < 0 || col == c || visited[row][col] == 1 || grid[row][col]!=target) {
            return;
        }
        visited[row][col] = 1;
        dfs(grid, target, visited, r, c, row + 1, col);
        dfs(grid, target, visited, r, c, row - 1, col);
        dfs(grid, target, visited, r, c, row, col - 1);
        dfs(grid, target, visited, r, c, row, col + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
       vector<vector<int>>visited(r,vector<int>(c,0));
       int ans=0;
        for (int i = 0; i < r ; i++) {
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                ans++;
                dfs(grid,'1',visited,r,c,i,j);
                }
            }
        }
        return ans;
    }
};