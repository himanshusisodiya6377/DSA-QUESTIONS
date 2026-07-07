class Solution {
public:
    vector<vector<int>>dp;
    int solve(int left,int right,vector<int>&cuts){

        if(dp[left][right]!=-1) return dp[left][right];
       
        if(right-left==1) return 0;

        int ans=INT_MAX;

        for(int i=left+1;i<right;i++){
            int cost=solve(left,i,cuts)+ solve(i,right,cuts) + cuts[right]-cuts[left];
            ans=min(ans,cost);
        }

        return dp[left][right]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        int m=cuts.size();
        dp.resize(m,vector<int>(m,-1));
        sort(cuts.begin(),cuts.end());
        return solve(0,m-1,cuts);   
    }
};