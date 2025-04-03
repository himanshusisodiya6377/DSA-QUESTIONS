class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
     int n=nums.size();
     if(n<=2) return 0;
     vector<int>premax(n,nums[0]);
     vector<int>suffmax(n,0);
     suffmax[n-2]=nums[n-1];
     suffmax[n-3]=max(nums[n-2],nums[n-1]);
     for(int i=1;i<n;i++){
        premax[i]=max(nums[i],premax[i-1]);
     }
     for(int i=n-4;i>=0;i--){
        suffmax[i]=max(nums[i+1],suffmax[i+1]);
     }
     long long result=INT_MIN;
     for(int i=0;i<n;i++){
        long long sum=(1LL*(premax[i]-nums[i]))*suffmax[i];
        if(sum>result) result=sum;
     }
     if(result<0) return 0;
     else return result;
    }
};