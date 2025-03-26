class Solution {
public:
     void dfs(int sr,int sc,int r,int c,vector<vector<int>>& image,int target,int color){
        if(sr<0 || sc<0 || sr==r || sc==c || image[sr][sc]==color || image[sr][sc]!=target){
            return;
        }
         image[sr][sc]=color;
        dfs(sr+1,sc,r,c,image,target,color);
        dfs(sr-1,sc,r,c,image,target,color);
        dfs(sr,sc+1,r,c,image,target,color);
        dfs(sr,sc-1,r,c,image,target,color);
     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r=image.size();
        int c=image[0].size();
        int target=image[sr][sc];
        dfs(sr,sc,r,c,image,target,color);
        return image;
    }
};