class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int r=matrix.size();
        int c=matrix[0].size();

        int ans=INT_MIN;

        vector<vector<int>>pre(r,vector<int>(c,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                pre[i][j]=matrix[i][j]+(i>0 ? pre[i-1][j] : 0)+(j>0 ? pre[i][j-1] : 0)-(i>0 && j>0 ? pre[i-1][j-1] : 0);
            }
        }

        for(int i=0;i<r;i++){ //for x1
        for(int j=i;j<r;j++){ //for x2

        for(int m=0;m<c;m++){ //for y1
            for(int l=m;l<c;l++){ //for y2
                
                int sum=pre[j][l]-(m>0 ? pre[j][m-1] : 0)-(i>0 ? pre[i-1][l] : 0)+(i>0 && m>0 ? pre[i-1][m-1] : 0);

                if(sum<=k){
                    ans=max(ans,sum);
                }
            }
        }

        }

        }

        return ans;
    }
};