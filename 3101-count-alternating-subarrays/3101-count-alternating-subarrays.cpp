class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
         long long n=nums.size();
        if(n==1) return 1;
        vector<long long>pre(n,0);
        for(int i=n-2;i>=0;i--){
            if(nums[i]!=nums[i+1]) pre[i]=pre[i+1]+1;
        }
        long long ans=0;
        for(int i=0;i<n;i++) ans+=pre[i];
        ans+=n;
        return ans;
    }
};