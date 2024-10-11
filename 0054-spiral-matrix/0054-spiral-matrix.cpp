class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size(); //rows
        int c=matrix[0].size(); //coloumn
        vector<int>v;
           int minr=0,minc=0,maxr=r-1,maxc=c-1;
           int count =0;
   while((minr<=maxr) && (minc<=maxc)){

        for(int j=minc;j<=maxc && count<r*c;j++){
            v.push_back(matrix[minr][j]);
            count++;
        }
        minr++;
        for(int k=minr;k<=maxr && count<r*c;k++){
             v.push_back(matrix[k][maxc]);
             count++;
        }
        maxc--;
         for(int l=maxc;l>=minc && count<r*c;l--){
             v.push_back(matrix[maxr][l]);
             count++;
        }
        maxr--;
         for(int m=maxr;m>=minr && count<r*c;m--){
             v.push_back(matrix[m][minc]);
             count++;
            
        }
         minc++;
}
        return v;
    }
};