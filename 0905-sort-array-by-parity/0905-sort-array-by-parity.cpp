class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(nums[i]%2==0) ans.push_back(nums[i]);
        // }
        //  for(int i=0;i<n;i++){
        //     if(nums[i]%2!=0) ans.push_back(nums[i]);
        // }
        // return ans;
        int i=0,j=n-1;
        while(i<j){
            if(nums[i]%2!=0 && nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else if(nums[i]%2==0 && nums[j]%2!=0){
                j--;
                i++;
            }
            else if(nums[i]%2==0 && nums[j]%2==0){
                i++;
            }
            else{
                j--;
            }
        }
        return nums;
    }
};