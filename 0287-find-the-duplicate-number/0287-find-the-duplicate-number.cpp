class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       for(int i=0;i<nums.size();i++){
        auto pos=find(nums.begin()+i+1,nums.end(),nums[i]);
        if(pos !=nums.end()) return nums[i];
       }
       return -1;
    }
};