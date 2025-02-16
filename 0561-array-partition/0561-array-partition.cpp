class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>sum;
        for(int i=0;i<nums.size()-1;i++){
            sum.push_back(min(nums[i],nums[i+1]));
        }
        sum.push_back(min(nums[0],nums[nums.size()-1]));
        sort(sum.begin(),sum.end());
        int ans=0;
        int k=nums.size()/2;
        for(int i=nums.size()-1;i>=0 && k>0;i-=2){
            ans+=sum[i];
            k--;
        }
        return ans;
    }
};