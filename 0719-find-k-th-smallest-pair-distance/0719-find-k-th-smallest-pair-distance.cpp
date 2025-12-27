class Solution {
public:
    int check(vector<int>&nums,int k,int mid){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int req=nums[i]+mid;
            int idx=upper_bound(nums.begin(),nums.end(),req)-nums.begin();
            if(idx<=i) continue;
            if(idx==nums.size()) idx--;
            if(nums[idx]>req) idx--;
            cnt+=(idx-i);
        }
        return cnt>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int lo=0,hi=nums[n-1]-nums[0];
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(nums,k,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};