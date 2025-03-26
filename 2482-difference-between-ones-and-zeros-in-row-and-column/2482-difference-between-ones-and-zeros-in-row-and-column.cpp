class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i=0;i<n;i++){
            int ans=0;
            for(int j=0;j<m;j++){
              if(grid[i][j]==1) ans++;
            }
            row[i]=ans;
        }
          for(int i=0;i<m;i++){
            int ans=0;
            for(int j=0;j<n;j++){
              if(grid[j][i]==1) ans++;
            }
            col[i]=ans;
        }
        vector<vector<int>>result(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[i][j]=(row[i]+col[j]-(n-row[i])-(m-col[j]));
            }
        }
        return result;
    }
};