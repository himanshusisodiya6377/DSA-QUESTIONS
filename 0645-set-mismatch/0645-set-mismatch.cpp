class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int n=nums.size();
       vector<int>v;
       int i=0;
       while(i<n){
        int coridx=nums[i]-1;
            if(nums[i]!=i+1){
                if(nums[i]==nums[coridx]){
                    v.push_back(nums[i]);
                    v.push_back(i+1);
                    return v;
                }
                else swap(nums[i],nums[coridx]);
            }
            else i++;
       }
       return v;
    }
};