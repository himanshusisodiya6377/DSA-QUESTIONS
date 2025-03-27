class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        map<int,vector<int>>mp;//ordered map he
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
          for(auto &v: mp){
              sort(begin(v.second),end(v.second));
            }
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    // vector<int>check=mp[i-j];
                    mat[i][j]=(mp[i-j])[0];
                    mp[i-j].erase(mp[i-j].begin());
                }
            }
            return mat;
    }
};