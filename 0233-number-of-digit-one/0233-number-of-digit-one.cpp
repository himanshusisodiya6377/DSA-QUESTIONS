class Solution {
public:
    int dp[10][2][10]; //index tight cnt

    int solve(string &s,int idx,bool tight,int cnt){
        if(idx==s.size()) return cnt;
        if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];

        int limit=(tight ? s[idx]-'0' : 9);
        int ans=0;
        for(int i=0;i<=limit;i++){
            int upd=cnt + (i == 1 ? 1 : 0);
            ans+=solve(s,idx+1,(tight & (i==s[idx]-'0')),upd);
        } 
        return ans;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string ri=to_string(n);
        string le=to_string(0);
        int right=solve(ri,0,1,0);
        int left=solve(le,0,1,0);
        return right-left;
    }
};