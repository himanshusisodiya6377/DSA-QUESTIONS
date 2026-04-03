class Solution {
  public:
    // unordered_set<string>st;
    // unordered_map<string,int>mp;
    vector<vector<int>>dp;
    int solve(int n,int x){
        if(n==0) {
            return 1;
        }
        //if last is what
        // if(mp.find(s)!=mp.end()) return mp[s];
        if(dp[n][x]!=-1) return dp[n][x];
        int a=0,b=0,c=0;
        if(x==-1 || x==0){
            // s.push_back('0');
            a=solve(n-1,0);
            // s.pop_back();
            
            // s.push_back('1');
            b=solve(n-1,1);
            // s.pop_back();
        }
        else{
            // s.push_back('0');
            c=solve(n-1,0);
            // s.pop_back();
        }
        
        return dp[n][x]=a+b+c;
    }
    int countStrings(int n) {
        // code here
        // string ans="";
        dp.resize(n+1,vector<int>(2,-1));
        return solve(n,0);
    }
};