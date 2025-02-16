class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // vector<int>v;
        int ans=INT_MAX;
        // for(int i=0;i<nums.size()-1;i++){
        //    v.push_back(min(nums[i],nums[i+1]));
        // }
        for(int i=0;i<nums.size()-1;i++){
           int x=nums[i+1]-nums[i];
           if(x<ans) ans=x;
        }
        return ans;
    }
};