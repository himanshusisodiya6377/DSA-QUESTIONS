class Solution {
public:

     void solve(vector<int>&nums,int tar,int sum,vector<vector<int>>&ans,vector<int>&temp,int idx){
 
    if(sum>tar) return;
    
    if(sum==tar){
        ans.push_back(temp);
        return;
    }

    
    for(int i=idx;i<nums.size();i++){
        sum+=nums[i];
        temp.push_back(nums[i]);
        solve(nums,tar,sum,ans,temp,i);
        sum-=nums[i];
        temp.pop_back();
    }

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
       vector<int>temp;
        solve(candidates,target,0,ans,temp,0);
        return ans;
    }
};