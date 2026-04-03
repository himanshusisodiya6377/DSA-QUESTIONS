class Solution {
public:
    int cnt=0;
    void solve(vector<int>&nums,int idx,int xr,int maxi){
        if(idx>=nums.size()){
            if(xr==maxi) cnt++;
            return;
        }
        // if(xr==maxi) cnt++;
        int new_xr=xr|nums[idx];
        solve(nums,idx+1,new_xr,maxi);
        solve(nums,idx+1,xr,maxi);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int xr=0;
        for(auto &it : nums) xr|=it;
        solve(nums,0,0,xr);
        return cnt;
    }
};