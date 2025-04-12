class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>&nums,vector<int>temp,int i){
     if(i==nums.size()){
        ans.push_back(temp);
        return;
     }
     temp.push_back(nums[i]);
     helper(nums,temp,i+1);
     temp.pop_back();
     helper(nums,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
       vector<int>temp;
       int i=0;
        helper(nums,temp,i);
        return ans;
    }
};