class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n=nums.size();
       //int count=0;
       int max=n/3;
       int idx=-1;
       vector<int>v;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[i]==nums[j]) count++;
        }
        if(count>max && nums[i]!=idx){
            idx=nums[i];
               v.push_back(idx);
        }
     
       }
       
       return v;
    }
};