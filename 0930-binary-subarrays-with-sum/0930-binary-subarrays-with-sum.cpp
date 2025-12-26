class Solution {
public:
    //note down chotu bhaiya method
    int solve(vector<int>&nums,int goal){
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            while(i<=j && sum>goal){
                sum-=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return solve(nums,goal)-solve(nums,goal-1);
    }
};