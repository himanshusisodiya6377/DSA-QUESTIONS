class Solution {
public:
    int N,pro;
    int mod=1e9+7;
    vector<vector<vector<int>>>dp;
    int solve(int idx,vector<int>&group,vector<int>&profit,int man,int prof){
        if(idx>=group.size()){
            if(prof>=pro) return 1;
            return 0;
        }

        if(dp[idx][man][prof]!=-1) return dp[idx][man][prof];
        int pick=0,not_pick=0;
        //can pick
        if(group[idx]<=man){
          pick=solve(idx+1,group,profit,man-group[idx],min(pro,
                    prof + profit[idx]));
          pick=pick%mod;
        }

        //can not
        not_pick=solve(idx+1,group,profit,man,prof);
        not_pick=not_pick%mod;
        return dp[idx][man][prof]=(pick+not_pick)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N=n;
        pro=minProfit;
        dp.resize(group.size(),vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));

       return solve(0,group,profit,n,0);
    }
};