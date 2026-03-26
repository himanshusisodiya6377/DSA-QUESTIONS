class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        
        unordered_map<int,int>mp;
        mp[0]=1;
        
        int xr=0;
        long ans=0;
        
        for(auto &it : arr){
            xr^=it;
            
            if(mp.find(xr^k)!=mp.end()) ans+=mp[xr^k];
            mp[xr]++;
        }
        
        return ans;
    }
};