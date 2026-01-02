class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp; //val eith index
        int j=0;
        int pre=0;
        int ans=0;
        mp[0]=-1;
        while(j<arr.size()){
            pre+=arr[j];
            if(mp.find(pre-k)!=mp.end()){
                ans=max(ans,j-mp[pre-k]);
            }
            if(mp.find(pre)==mp.end())
            mp[pre]=j;
            j++;
        }
        return ans;
    }
};