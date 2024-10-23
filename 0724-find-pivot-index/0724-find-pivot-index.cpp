class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n=nums.size();
      //sort(nums.begin(),nums.end());
      int pre[n];
      pre[0]=0;
      for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+nums[i-1];
      }  
      int suff[n];
      suff[n-1]=0;
       for(int i=n-2;i>=0;i--){
        suff[i]=suff[i+1]+nums[i+1];
      }  
      for(int i=0;i<n;i++){
        if(pre[i]==suff[i]) return i;
      }
      return -1;
    }
};