class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[j-i].push_back(grid[i][j]);
            }
        }

        for(auto &it : mp){
            if(it.first<=0){
                sort(it.second.begin(),it.second.end());
            }
            else{
                 sort(it.second.begin(),it.second.end());
                 reverse(it.second.begin(),it.second.end());
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=mp[j-i][mp[j-i].size()-1];
                mp[j-i].pop_back();
            }
        }

        return grid;
    }
};