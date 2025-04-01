class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int n=nums.size();
       vector<int>v;
       int i=0;
       while(i<n){
        int coridx=nums[i]-1;
        if(nums[coridx]==nums[i]) i++;
        else swap(nums[i],nums[coridx]);
       }
       for(int i=0;i<n;i++){
        if(nums[i]!=i+1){
            v.push_back(nums[i]);
            v.push_back(i+1);
        }
       }
       return v;
    }
};