class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int i=0,j=k-1;
        while(j<n){
            mini=min(mini,nums[j]-nums[i]);
            i++;
            j++;
        }
        if(mini==INT_MAX) return 0;
        return mini;
    }
};