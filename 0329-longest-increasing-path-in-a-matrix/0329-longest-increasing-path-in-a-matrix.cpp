class Solution {
public:
    vector<vector<int>>dp;
    vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    int dfs(vector<vector<int>>&matrix,int i,int j){
       if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size()) return 0;

    //    visit[i][j]=true;
    if(dp[i][j]!=-1) return dp[i][j];
       
       int maxi=0;
       for(int k=0;k<dir.size();k++){
        int new_i=i+dir[k].first;
        int new_j=j+dir[k].second;
        
        if(new_i<0 || new_i>=matrix.size() || new_j<0 || new_j>=matrix[0].size()) continue;
        if(matrix[new_i][new_j]<=matrix[i][j]) continue;
        
        int ans=1+dfs(matrix,new_i,new_j);
        maxi=max(maxi,ans);
       }

       return dp[i][j]=maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;

        int r=matrix.size();
        int c=matrix[0].size();

        dp.resize(r,vector<int>(c,-1));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // vector<vector<bool>>visit(r,vector<bool>(c,false));
                int s=1+dfs(matrix,i,j);
                ans=max(ans,s);
            }
        }

        return ans;
    }
};