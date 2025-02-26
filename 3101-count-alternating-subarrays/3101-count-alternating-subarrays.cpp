class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
         long long n=nums.size();
        if(n==1) return 1;
        // vector<long long>pre(n,0);
        long long ans=n;
        long long count=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                count++;
                ans+=count;
            }
            else count=0;
        }
        return ans;
    }
};