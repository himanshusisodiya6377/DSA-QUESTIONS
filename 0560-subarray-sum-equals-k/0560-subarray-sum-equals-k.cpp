class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int ans=0;
        for(auto i : nums){
          sum+=i;
          int diff=sum-k;
          if(mp.find(diff)!=mp.end()){
              ans+=mp[diff];
          }
          mp[sum]++;
        }
        return ans;
    }
};