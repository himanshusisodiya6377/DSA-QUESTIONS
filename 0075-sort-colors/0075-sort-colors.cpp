class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
       for(int i=0;i<n;i++){
       // bool flag=true;
        for(int j=0;j<n-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                //flag=false;
            }
          
        }
         // if(flag==true) break;
       }
       return;
    }
};