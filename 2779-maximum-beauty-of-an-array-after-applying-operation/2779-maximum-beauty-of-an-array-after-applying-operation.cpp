class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       int i=0,j=0;
       int maxi=0;
       while(j<n){
        //   j++;
          maxi=max(maxi,j-i);
          while(i<=j && (nums[j]-nums[i])>2*k) i++;
          j++;
       } 
       maxi=max(maxi,j-i);
       return maxi;
    }
};