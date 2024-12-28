class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         vector<vector<int>>v(m,vector<int>(n));
         if(original.size()!=m*n) return {};
         int k=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v[i][j]=original[k];
                k++;
            }
         }
         return v;
    }
};