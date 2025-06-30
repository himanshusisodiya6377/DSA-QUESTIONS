class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            while(i<n && nums[i]==i+1) i++;
            while( i<n && nums[i]!=(i+1)){
            if(nums[i]==nums[nums[i]-1]){
                 i++;
                 break;
            }
            else swap(nums[i],nums[nums[i]-1]);
            }        
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=(i+1)) ans.push_back(i+1);
        }
        return ans;
    }
};