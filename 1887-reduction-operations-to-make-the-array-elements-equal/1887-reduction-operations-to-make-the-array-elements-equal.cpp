class Solution {
public:
    int reductionOperations(vector<int>& nums) {
      int n=nums.size();
      if(n==1) return 0;
      int un=1;
      sort(nums.begin(),nums.end());
       for(int i=1;i<n;i++){
          if(nums[i]!=nums[i-1]) un++;
      } 
      if(nums[0]==nums[n-1]) return 0;
      int ans=un-1;
      for(int i=n-2;i>=0;i--){
        if(nums[i]!=nums[i+1]){
            un--;
            ans+=(un-1);
        }
        else{
            ans+=(un-1);
        }
      }
      return ans;
    }
};