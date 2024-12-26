class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int size=m*n;
        vector<int>v;
        vector<int>ind(size,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 ind[grid[i][j]-1]++;
            }
        }
        int miss;
        int rep;
        for(int i=0;i<ind.size();i++){
            if(ind[i]==0) miss=i+1;
            if(ind[i]==2) rep=i+1;
        }
        v.push_back(rep);
        v.push_back(miss);
        return v;
    }
};