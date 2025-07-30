class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        //we can also do it in one go 
        //we can maintain two variable maxlength and maxvalue 
        //we let first value be max till we got bigger number than it 
        //according to maxvalue we going to calculate maxlength
        //samaj na aaye to codewithmik dekho
        if(n==1) return 1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(ans<nums[i]) ans=nums[i]; 
        }
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