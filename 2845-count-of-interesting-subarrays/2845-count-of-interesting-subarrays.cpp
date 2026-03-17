class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        
        int n=nums.size();

        unordered_map<int,int>mp;
        
        vector<int>pre(n,0);
        
        //getting prefix sum
        mp[0]=1;
        for(int i=0;i<n;i++){
           pre[i]=(nums[i]%m==k ? 1 : 0)+(i>0 ? pre[i-1] : 0);
        }
        
        long long ans=0;
        for(int i=0;i<n;i++){
           ans+=mp[(pre[i]+m-k)%m];
           mp[pre[i]%m]++;
        }

        return ans;
    }
};