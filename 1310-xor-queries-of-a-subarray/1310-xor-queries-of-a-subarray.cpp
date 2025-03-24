class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        int r=queries.size();
        vector<int>pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^arr[i];
        }
        vector<int>ans(r,0);
        for(int i=0;i<r;i++){
        if(queries[i][0]==0){
            ans[i]=pre[queries[i][1]];
            }
        else{
           int xoro=(pre[queries[i][1]]^pre[queries[i][0]-1]);
           ans[i]=xoro;
        }
        }
        return ans;
    }
};