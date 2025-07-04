class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int r=mat.size();
        int c=mat[0].size();
        for(int i=0;i<r;i++){
            for(int j=1;j<c;j++){
                mat[i][j]=mat[i][j]+mat[i][j-1];
            }
        }

      vector<vector<int>>ans(r,vector<int>(c,0));
      for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int x1=i-k,x2=i+k;
            int y1=j-k,y2=j+k;
            if(x1<0) x1=0;
            if(y1<0) y1=0;
            if(x2>=r) x2=r-1;
            if(y2>=c) y2=c-1;
            int sum=0;

            if(x1==0 && y1==0){
              for(int i=0;i<=x2;i++){
                    sum+=mat[i][y2];
              }
            }
            else{
                if(y1!=0){
                  for(int i=x1;i<=x2;i++){
                    sum+=(mat[i][y2]-mat[i][y1-1]);
                }
                }
                else{
                    for(int i=x1;i<=x2;i++){
                        sum+=mat[i][y2];
                    }
                }
            }
            ans[i][j]=sum;
        }
      }
      return ans;
    }
};