class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int lo = 0, hi = *max_element(nums.begin(), nums.end());

        int ans=INT_MAX;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            int take=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    take++;
                    i++;
                }
            }

            if(take>=k){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
    }
};
