class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    //   int n=nums.size(), count=0, max=0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==1){
    //             count++;
    //         }
    //         else{
    //             if(count>max){
    //                 max=count;
    //                 count=0;
    //             }
    //         }
    //     }
    //       if(count>max){
    //                 max=count;
    //             }
    //         return max;
             int maxi = 0;//contains the value of consecutive no's of 1
       int count=0;//count the no.'s of 1 consecutively and reset to 0 when 0 come
       for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;//lineraly increase the value when 1 comes
            }else{
                maxi = max(maxi,count);//store the value of max no of 1 in consecutively order
                count = 0;//suddenly count = 0 , 
            }
            maxi = max(maxi,count);
       }
       return maxi;//himanshukansal101
        }
        
    
};