class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int r=row.size(),c=col.size();

        vector<vector<int>>ans(r,vector<int>(c,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int x=min(row[i],col[j]);
                // cout<<x<<endl;
                ans[i][j]=x;
                row[i]-=x;
                col[j]-=x;
            }
        }

        return ans;
    }
};