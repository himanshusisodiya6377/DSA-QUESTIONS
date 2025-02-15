class Solution {
public:
    int captureForts(vector<int>& nums) {
    int n=nums.size();
    int start=0;
    int count=0,max=0;
    for(int j=0;j<n;j++){
        if(nums[j]==1 || nums[j]==-1){
           if(start==0) start=nums[j];
           else{
                  if(start!=nums[j]){
                        if(count>max) {
                            max=count;
                            count=0;
                            start=nums[j];
                        }
                        else{
                             count=0;
                            start=nums[j];
                        }
                    }
                    else count=0;
           }
        }
        else{
            if(start!=0){
                if(nums[j]==0) count++;
            }
        }
    }
    return max;
    }
};