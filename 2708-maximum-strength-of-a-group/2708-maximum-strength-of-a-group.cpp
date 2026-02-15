class Solution {
public:
    long long ans=INT_MIN;
    void solve(vector<int>&nums,int idx,long long prod){
        if(idx>=nums.size()){
            ans=max(ans,prod);
            return;
        }

        //include it
        long long t=(prod==INT_MIN ? nums[idx] : prod*nums[idx]);
        solve(nums,idx+1,t);

        //not
        solve(nums,idx+1,prod);
    }
    long long maxStrength(vector<int>& nums) {
        solve(nums,0,INT_MIN);
        return ans;
    }
};