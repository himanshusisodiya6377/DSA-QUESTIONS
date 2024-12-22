class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==0) continue;
            else if((nums[i]%3)!=0){
                int x=nums[i]%3;
                if(x<=1) sum+=x;
                else sum+=(3-x);
            } 
        }
        return sum;
    }
};