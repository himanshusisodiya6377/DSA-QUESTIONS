class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int r=grid.size();
        // int c=grid[0].size();

        vector<vector<int>>ans(r-2,vector<int>(r-2,0));

        for(int i=0;i<r-2;i++){
            for(int j=0;j<r-2;j++){
                int maxi=0;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                         maxi=max(maxi,grid[k][l]);
                    }
                }
                ans[i][j]=maxi;
            }
        }

        return ans;
    }
};