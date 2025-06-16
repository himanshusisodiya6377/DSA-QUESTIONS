class Solution {
public:

     void dfs(vector<vector<int>>&heights, vector<vector<bool>>&visit,int row,int col,int i,int j,int base){
        if(i<0 || j<0 || i>=row || j>=col || visit[i][j] || heights[i][j]<base) return;
        visit[i][j]=true;

        //right
        // if(i>=0 && (j+1)>=0 && i<row && (j+1)<col && heights[i][j]>=heights[i][j+1]){
             dfs(heights,visit,row,col,i,j+1,heights[i][j]);
        //left
        //  if(i>=0 && (j-1)>=0 && i<row && (j-1)<col && heights[i][j]>=heights[i][j-1]){
             dfs(heights,visit,row,col,i,j-1,heights[i][j]);
        //}
        //up
         //if((i-1)>=0 && j>=0 && (i-1)<row && j<col && heights[i][j]>=heights[i-1][j]){
             dfs(heights,visit,row,col,i-1,j,heights[i][j]);
        //}
        //down
         //if((i+1)>=0 && j>=0 && (i+1)<row && j<col && heights[i][j]>=heights[i+1][j]){
             dfs(heights,visit,row,col,i+1,j,heights[i][j]);
        //}
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(r,(vector<bool>(c,false)));
        vector<vector<bool>>atlantic(r,(vector<bool>(c,false)));
         //for pacific horizontal row
        for(int i=0;i<r;i++){
            if(pacific[i][0]!=true){
           dfs(heights,pacific,r,c,i,0,heights[i][0]);
            }
        }
        //vertical row
        for(int i=0;i<c;i++){
            if(pacific[0][i]!=true){
           dfs(heights,pacific,r,c,0,i,heights[0][i]);
            }
        }

        //atlantic
          for(int i=0;i<c;i++){
            if(atlantic[r-1][i]!=true){
           dfs(heights,atlantic,r,c,r-1,i,heights[r-1][i]);
            }
        }

        //
          for(int i=0;i<r;i++){
            if(atlantic[i][c-1]!=true){
           dfs(heights,atlantic,r,c,i,c-1,heights[i][c-1]);
            }
        }

         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
              if(pacific[i][j]==atlantic[i][j]){
                ans.push_back({i,j});
              }
            }
        }

        return ans;
    }
};