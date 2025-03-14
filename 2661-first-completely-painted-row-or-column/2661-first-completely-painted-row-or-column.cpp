class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<r;i++){
            // vector<int>v;
            for(int j=0;j<c;j++){
                mp.insert({mat[i][j], {i,j}});
            //    v.push_back(i);
            //    v.push_back(j);
            //    mp[mat[i][j]].push(v);
            }
        }
        vector<int>row(r,0);
        vector<int>col(c,0);
        for(int i=0;i<arr.size();i++){
            vector<int>v=mp[arr[i]];
            // if(mp.find(arr[i])!=mp.end()){
                row[v[0]]++;
                col[v[1]]++;
                if(row[v[0]]==c) return i;
                if(col[v[1]]==r) return i;
            // }
        }
        return -1;
    }
};