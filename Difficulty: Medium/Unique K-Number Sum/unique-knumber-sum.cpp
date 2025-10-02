class Solution {
  public:
  
    void solve(int n,int sum,vector<int>v,int idx,vector<vector<int>>&ans,int k){
        if(sum>n) return;
        if(sum==n){
            if(v.size()==k) ans.push_back(v);
            return;
        }
        
        for(int i=idx+1;i<=9;i++){
            // vector<int>v;
            sum+=i;
            v.push_back(i);
            solve(n,sum,v,i,ans,k);
            v.pop_back();
            sum-=i;
        }
    }
  
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>>ans;
        int sum=0;
        
        for(int i=1;i<=9;i++){
            vector<int>v;
            sum+=i;
            v.push_back(i);
            solve(n,sum,v,i,ans,k);
            v.pop_back();
            sum-=i;
        }
        return ans;
    }
};