class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

       int r=mat.size();
       int c=mat[0].size();

       vector<vector<int>>pre(r,vector<int>(c,0));

       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int sum=mat[i][j]+(i>0 ? pre[i-1][j] : 0)+(j>0 ? pre[i][j-1] : 0)-((i>0 && j>0) ? pre[i-1][j-1] : 0);
            pre[i][j]=sum;
        }
       }   

       int ans=0;
       
       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            //now starting coordinates are fixed i and j
            int endx=i,endy=j;
            while(endx<r && endy<c){
                int sum=pre[endx][endy]-(j>0 ? pre[endx][j-1] : 0)-(i>0 ? pre[i-1][endy] : 0)+(i>0 && j>0 ? pre[i-1][j-1] : 0);
                endx++;
                endy++;
                if(sum<=threshold){
                    ans=max(ans,endx-i);
                }
            }
        }
       }
       return ans;
    }
};