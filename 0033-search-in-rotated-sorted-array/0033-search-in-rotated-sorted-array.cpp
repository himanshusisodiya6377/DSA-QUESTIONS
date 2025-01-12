class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n=nums.size();
      int lo=0,hi=n-1;
      if(n==1){
        if(nums[0]==target) return 0;
        else return -1;
      }
      while(lo<=hi){
        int mid=(lo+hi)/2;
        if(nums[mid]==target) return mid;
        else if(nums[lo]<nums[mid]){//right part is sorted
             if(target<=nums[mid] && target>=nums[lo]) hi=mid-1;
             else lo=mid+1;
        }
        else{//definately left part is sorted
             if(target<=nums[hi] && target>=nums[mid+1]) lo=mid+1;
             else hi=mid-1;
        }
      }
      return -1;
    }
};