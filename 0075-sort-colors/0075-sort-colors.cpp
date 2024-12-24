class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
      int lo=0,mid=0;
      int hi=n-1;//indexed
      while(mid<=hi){
       if(nums[mid]==0) {
        swap(nums[lo],nums[mid]);
        mid++;
        lo++;
       }
       else if(nums[mid]==2){
        swap(nums[mid],nums[hi]);
        hi--;
       }
       else{
        mid++;
       }
      }
      return;
    }
};