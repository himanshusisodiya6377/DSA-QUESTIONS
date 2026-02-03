class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        bool flag1=false,flag2=false,flag3=true;
        while(i<n-1 && nums[i+1]>nums[i]){
            i++;
            flag1=true;
        }
        while(j>=1 && nums[j]>nums[j-1]) {
            j--;
            flag2=true;
        }

        if(j<=i) return false;
        // if(j-i==2) return true;

        for(int k=i;k<j;k++){
            if(nums[k]<=nums[k+1]){
                flag3=false;
                break;
            }
        }
        return flag1 && flag2 && flag3;
    }
};