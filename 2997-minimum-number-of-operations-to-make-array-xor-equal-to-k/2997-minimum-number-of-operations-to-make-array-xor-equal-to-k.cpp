class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int result=nums[0];
        for(int i=1;i<n;i++){
            result=result^nums[i];
        }
        int get=result^k;
        return __builtin_popcount (get);
    }
};