class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadanes Algorithm
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(maxi<sum) maxi=sum;
            if(sum<0) sum=0;
        }
        return maxi;
    }
};