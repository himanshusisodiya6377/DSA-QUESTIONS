class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return {-1,-1};
        int lo=0,hi=n-1;
        int first=-1;
        while(lo<=hi){//lower bound
            int mid=(lo+hi)/2;
            if(nums[mid]<target) lo=mid+1;
            else if(nums[mid]>=target) hi=mid-1;
        }
        if(nums[lo]==target) first=lo;
        lo=0,hi=n-1;
        int last=-1;
        while(lo<=hi){//uppar bound
            int mid=(lo+hi)/2;
            if(nums[mid]>target) hi=mid-1;
            else if(nums[mid]<=target) lo=mid+1;
        }
        if(nums[hi]==target) last=hi;
        return {first,last};
    }
};