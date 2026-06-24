class Solution {
public:
    bool check(vector<int>&nums,int mid){
        if(mid%2==0){
            if(nums[mid]==nums[mid+1]) return true;
        }
        else if(nums[mid]==nums[mid-1]) return true;
        return false;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans=-1;

        int lo=0,hi=n-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(check(nums,mid)){
                lo=mid+1;
            }else{
                ans=nums[mid];
                hi=mid-1;
            }
        }
        return ans;
    }
};