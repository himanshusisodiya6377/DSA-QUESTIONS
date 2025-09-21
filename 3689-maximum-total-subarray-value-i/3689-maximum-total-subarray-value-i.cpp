class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long n=nums.size();
        long long mini=INT_MAX;
        long long maxi=INT_MIN;
        for(auto it : nums){
            mini=min(mini,(long long)it);
            maxi=max(maxi,(long long)it);
        }
        return (maxi-mini)*(long long)k;
    }
};