class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        int count=1;
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int maxi=INT_MIN;
        for(int i=1;i<n;i++){
            if((nums[i]-mini)>k){
                count++;
                mini=nums[i];
            }
        }
        return count;
    }
};