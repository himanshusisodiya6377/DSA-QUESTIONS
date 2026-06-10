class Solution {
public:
    int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();

        sort(arr.begin(),arr.end());
        unordered_set<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
            st.insert(arr[i]);
        }

        vector<int>dp(n,1);

        for(int i=0;i<n;i++){
            //fetch arr[i] as root and look before is there any factor available
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && st.count(arr[i]/arr[j])){
                    int right=arr[i]/arr[j];
                    if(right<arr[i]){
                        if(arr[j] != right) dp[i] =(dp[i] + (1LL*dp[mp[arr[j]]]*dp[mp[right]])%mod) %mod;
                        else dp[i] = (dp[i] + (1LL*dp[mp[arr[j]]]*dp[mp[right]])% mod) % mod;
                    }
                }
            }
        }

        int ans=0;
        for(auto &it : dp) {
            // cout<<it<<" ";
            ans+=it;
            ans=ans%mod;
        }
        
        return ans;
    }
};