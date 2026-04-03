class Solution {
  public:
    vector<vector<int>>dp;
    bool solve(vector<int>&arr,int k,int idx){
        if(k==0) return true;
        if(idx>=arr.size()){
            return false;
        }
        
        if(dp[idx][k]!=-1) return dp[idx][k];
        
        bool inc=false;
        
        if((k-arr[idx])>=0){
            inc=solve(arr,k-arr[idx],idx+1);
            if(inc) return dp[idx][k]=true;
        }
        
        bool not_inc=solve(arr,k,idx+1);
        if(not_inc) return dp[idx][k]=true;
        
        return dp[idx][k]=inc | not_inc;
        
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        // sort(arr.rbegin(),arr.rend());
        dp.resize(n+1,vector<int>(k+1,-1));
        return solve(arr,k,0);
    }
};