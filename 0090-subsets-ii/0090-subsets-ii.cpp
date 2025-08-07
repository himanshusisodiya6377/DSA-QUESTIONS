class Solution {
public:

    void solve(vector<int>&nums,int start,vector<vector<int>>&ans,vector<int>&temp){

         ans.push_back(temp);

         for(int i=start;i<nums.size();i++){

           if(i>start && nums[i]==nums[i-1]) continue;

           temp.push_back(nums[i]);
        //    visit[i]=true;

           solve(nums,i+1,ans,temp);

           temp.pop_back();
        //    visit[i]=false;

         }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // vector<bool>visit(n,false);
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,0,ans,temp);
        return ans;
    }
};