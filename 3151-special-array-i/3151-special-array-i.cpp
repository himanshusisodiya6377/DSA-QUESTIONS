class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        bool flag;
        if(nums[0]%2==0) flag=true;
        else flag=false;
        for(int i=1;i<n;i++){
        if(flag==true){
            if(nums[i]%2!=0){
                flag=false;
            }
            else return false;
        }
        else{
            if(nums[i]%2==0) flag=true;
            else return false;
        }
        }
        return true;
    }
};