class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& inter) {
        int n=inter.size();

        vector<int>ans(n,-1);

        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inter[i][0]]=i;
        }

        sort(inter.begin(),inter.end());

        for(int i=0;i<n;i++){
           int end=inter[i][1];
           auto it=lower_bound(inter.begin(),inter.end(),vector<int>{end, INT_MIN})-inter.begin();
           if(it!=n){
            ans[mp[inter[i][0]]]=mp[inter[it][0]];
           }
        }

       
        return ans;
    }
};