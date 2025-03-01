class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans=INT_MIN;
        int sum=0;
        int i=0;
        while(i<n){
            if(nums[i]<nums[i+1]){
                sum+=nums[i];
                i++;
             }
            else{
                sum+=nums[i];
                ans=max(ans,sum);
                sum=0;
                i++;
            }
        }
        return ans;
    }
};