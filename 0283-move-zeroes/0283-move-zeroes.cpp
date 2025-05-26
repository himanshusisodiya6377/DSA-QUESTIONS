class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        //bubble sort
        // for (int i = 0; i < n; i++) {
        //     bool flag = true;
        //     for (int j = 0; j < n - 1 - i; j++) {

        //         if (nums[j] == 0 && nums[j + 1] != 0) {
        //             swap(nums[j], nums[j + 1]);
        //             flag = false;
        //         }
        //     }
        //     if (flag == true)
        //         break;
        // }
        int i=0,j=1;
        while( i<n && j<n){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i],nums[j]);
                while(i<n && nums[i]!=0) i++;
                while(j<n && nums[j]==0) j++;
            }
            else if(nums[i]==0 && nums[j]==0) j++;
            else{
                i++;
                j++;
            }
        }
     
    }
};