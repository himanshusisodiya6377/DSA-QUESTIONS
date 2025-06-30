class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        sort(nums.begin(),nums.end());
        for(int m=0;m<n;m++){
            if(nums[m]!=i) continue;
            else i++;
        }
        return i;
    }
};