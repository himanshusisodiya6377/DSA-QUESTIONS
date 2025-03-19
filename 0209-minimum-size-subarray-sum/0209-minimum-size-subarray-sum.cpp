class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int length=INT_MAX;
        int sum=0;
        while(j<n){
          if(sum<target){
            sum+=nums[j];
            if(sum<target) j++;
          }
          else {
            length=min(length,j-i+1);
            sum-=nums[i];
            i++;
            if(sum<target) j++;
          }
        }
        // length=min(length,j-i);
        return (length == INT_MAX) ? 0 : length;
    }
};