class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
          int n=nums.size();
      int lo=0,hi=n-1;
      if(n==1){//special case
        if(nums[0]==target) return true;
        else return false;
      }
      while(lo<=hi){
        int mid=(lo+hi)/2;
        if(nums[mid]==target) return true;
        else if(nums[lo]<nums[mid]){//if right part is sorted
             if(target<=nums[mid] && target>=nums[lo]) hi=mid-1;
             else lo=mid+1;
        }
        else{//definately left part is sorted
             if(target<=nums[hi] && target>=nums[mid+1]) lo=mid+1;
             else hi=mid-1;
        }
      }
      return false;;
    }
}; 