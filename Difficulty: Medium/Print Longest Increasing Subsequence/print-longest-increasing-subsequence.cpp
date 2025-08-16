class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[i]<(dp[j]+1)){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
        }
        
        vector<int>ans;
        
        int idx=0;
        int maxi=1;
        
        for(int i=0;i<n;i++){
            if(maxi<dp[i]){
                maxi=dp[i];
                idx=i;
            }
        }
        
        
        while(parent[idx]!=-1){
            ans.push_back(arr[idx]);
            idx=parent[idx];
        }
        
        ans.push_back(arr[idx]);
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};