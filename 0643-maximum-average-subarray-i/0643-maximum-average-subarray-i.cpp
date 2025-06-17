class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int n=nums.size();
       int i=1,j=k;
       int sum=0;
       for(int m=0;m<k;m++){
       sum+=nums[m];
       }
       double maxi=(double)sum/k;
       while(j<n){
          sum-=nums[i-1];
          sum+=nums[j];
          double avg=(double)sum/k;
          maxi=max(maxi,avg);
          i++;
          j++;
       }  
       return maxi;
    }
};