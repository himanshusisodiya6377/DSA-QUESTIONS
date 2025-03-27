class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        int m=nums.size();
        int n=(nums.size())/3;
       
        for(int i=0;i<m;i++){
             int count=1;
            for(int j=i+1;j<m;j++){
                if(nums[i]==nums[j]) count++;
            }
            if(count>n) v.push_back(nums[i]);
        }
        return v;
    }
};