class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s,int idx,char prev,int k){
        if(idx>=s.length()) return 0;
        if(dp[idx][(prev=='#' ? 26 : prev-'a')]!=-1) return dp[idx][(prev=='#' ? 26 : prev-'a')];
        int ans=0;
        //i can take it 
        // cout<<abs((prev-'a')-(s[idx]-'a'))<<endl;
        if(prev=='#' || abs((prev-'a')-(s[idx]-'a'))<=k){
            ans=max(ans,1+solve(s,idx+1,s[idx],k));
            // cout<<ans<<endl;
        }

        ans=max(ans,solve(s,idx+1,prev,k));
        // cout<<ans<<endl;
        return dp[idx][(prev=='#' ? 26 : prev-'a')]=ans;
    }
    int longestIdealString(string s, int k) {
        int n=s.length();
        dp.resize(n,vector<int>(27,-1));
        return solve(s,0,'#',k);
    }
};