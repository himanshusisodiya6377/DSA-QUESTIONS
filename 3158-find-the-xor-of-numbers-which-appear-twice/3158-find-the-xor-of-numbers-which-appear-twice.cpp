class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i=0;i<nums.size()-1;i++){
                 if(nums[i]==nums[i+1]){
                    v.push_back(nums[i]);
                    i++;
                 }
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans^=v[i];
        }
        return ans;
    }
};