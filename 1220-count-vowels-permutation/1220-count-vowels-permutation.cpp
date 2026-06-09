class Solution {
public:
    int cnt;
    unordered_map<char, vector<char>> mp;
    vector<vector<int>>dp;
    int mod=1e9+7;
    int check(char ch, int n) {
        if (n == 0)
            return 1;

        if(dp[n][ch-'a']!=-1) return dp[n][ch-'a'];
            int ans=0;
            for(auto &it : mp[ch]){
                ans+=check(it,n-1);
                ans=ans%mod;
            }
            // cout<<ans<<" "<<ch<<endl;
            return dp[n][ch-'a']=ans;
    }
    int countVowelPermutation(int n) {
        cnt = 0;
        dp.resize(n+1,vector<int>(26,-1));
        mp['a'] = {'e'};
        mp['e'] = {'a', 'i'};
        mp['i'] = {'a', 'e', 'o', 'u'};
        mp['o'] = {'i', 'u'};
        mp['u'] = {'a'};
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < 5; i++) {
            cnt += check(v[i], n - 1);
            cnt=cnt%mod;
            // cout<<v[i]<<endl;
         }
        return cnt;
    }
};