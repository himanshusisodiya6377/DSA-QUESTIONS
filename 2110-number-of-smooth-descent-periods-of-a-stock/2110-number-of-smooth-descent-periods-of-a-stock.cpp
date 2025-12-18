class Solution {
public:
    vector<int>dp;
    long long solve(vector<int>&prices,int idx){
        if( idx>=prices.size() || prices[idx-1]-prices[idx]!=1) return 0;
         
        if(dp[idx]!=-1) return dp[idx];
        long long ans=1+solve(prices,idx+1);

        return dp[idx]=ans;
    }
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 1;
        dp.resize(n+1,-1);
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(1+solve(prices,i+1));
            // cout<<ans<<endl;
        }
        return ans;
    }
};