class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
       int n=nums.size();
    //    vector<int>cnt(n);
       unordered_map<int,long long>mp;
       mp[0]=1;
       int pre=0;
       long long ans=0;
       for(auto &it : nums){
          pre=(pre+it)%k;
          ans+=mp[pre]++;
       }

       for(int i=0;i<n ;){
        int j=i;
        while(j<n && nums[j]==nums[i]) j++;
        int l=j-i;
        for(int ll=1;ll<l;++ll){
            if((1LL*ll*nums[i])%k==0) ans-=(l-ll);
        }
        i=j;
       }

       return ans;

    }
};