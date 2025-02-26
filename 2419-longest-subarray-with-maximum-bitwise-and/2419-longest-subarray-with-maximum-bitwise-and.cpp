class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        vector<int>copy=nums;
        sort(copy.begin(),copy.end());
        int ans=copy[n-1];
        int maxi=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ans) count++;
            else{
                   if(maxi<count) maxi=count;
                   count=0;
            }
        }
        if(count>maxi) maxi=count;
        return maxi;
    }
};