class Solution {
public:
    bool check(vector<int>&nums,int mid,int p){
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]<=mid) {
                cnt++;
                i++;
            }
            if(cnt>=p) return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        int lo=0,hi=1e9;
        int ans=0;
        sort(nums.begin(),nums.end());
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(nums,mid,p)){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return ans;
    }
};