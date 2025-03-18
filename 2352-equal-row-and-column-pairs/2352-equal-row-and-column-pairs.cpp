class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>row;
        int n=grid.size();
         for(int i=0;i<n;i++){
            row[grid[i]]++;
        }
        map<vector<int>,int>col;
    
        for(int i=0;i<n;i++){
            vector<int>a;
            for(int j=0;j<n;j++){
                a.push_back(grid[j][i]);
            }
           col[a]++;
        }
        int count=0;
        for( auto v : row){
            vector<int>num=v.first;
            if(col.find(num)!=col.end()){
                int x=row[num];
                int y=col[num];
                count+=x*y;
            }
        }
        return count;
    }
};