class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>v;
        for(int i=1;i<=rowIndex+1;i++){
            vector <int>a(i);
            v.push_back(a);
        }
        for(int i=0;i<=rowIndex;i++){
            for(int j=0;j<=i;j++){
                if((j==0) || (i==j)) v[i][j]=1;
                else v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
        vector<int>v3;
        int k=rowIndex;
        for(int l=0;l<rowIndex+1;l++){
            v3.push_back(v[k][l]);
        }
        return v3;

    }
};