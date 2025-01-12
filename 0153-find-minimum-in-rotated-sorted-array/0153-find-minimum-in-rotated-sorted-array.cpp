class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        int mini=INT_MAX;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]<mini) mini=nums[mid];
            if(nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid-1;
        }
        return mini;
    }
};