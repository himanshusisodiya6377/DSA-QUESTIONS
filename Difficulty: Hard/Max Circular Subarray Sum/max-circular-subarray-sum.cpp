class Solution {
  public:
    int maxCircularSum(vector<int> &nums) {
        // code here
        int n=nums.size();

        int maxi_sum=INT_MIN;

        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi_sum=max(maxi_sum,sum);
            if(sum<0) sum=0;
        }
        
        if(maxi_sum<0) return maxi_sum;
        
        int mini_sum=INT_MAX;

        sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            mini_sum=min(mini_sum,sum);
            if(sum>0) sum=0;
        }

        sum=0;
        
        for(auto it : nums) sum+=it;

      return max(maxi_sum,sum-mini_sum);
    }
};