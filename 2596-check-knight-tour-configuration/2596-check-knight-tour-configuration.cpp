class Solution {
public:

    vector<pair<int,int>>dir={{-1,-2},{-2,-1},{-1,2},{-2,1},{1,2},{2,1},{2,-1},{1,-2}};

    bool isvalid(int x,int y,vector<vector<int>>&grid){
   
      if(x<0 || y<0 || x>=grid.size() || y>=grid.size()) return false;

      return true;  

    }

    bool solve(vector<vector<int>>&grid,vector<vector<int>>&ans,int n,int row,int col){

        if(n>=(grid.size()*grid[0].size())) return true;
        
        if(ans[row][col]!=grid[row][col]) return false;
  
        for(auto it : dir){
            int r=row+it.first;
            int c=col+it.second;
            if(isvalid(r,c,grid) && ans[r][c]==-1){
                ans[r][c]=n;
                if(solve(grid,ans,n+1,r,c)) return true;
                ans[r][c]=-1;
            }
        }

        return false;

    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(n,vector<int>(n,-1));
        ans[0][0]=0;
       return solve(grid,ans,1,0,0);
    }
};