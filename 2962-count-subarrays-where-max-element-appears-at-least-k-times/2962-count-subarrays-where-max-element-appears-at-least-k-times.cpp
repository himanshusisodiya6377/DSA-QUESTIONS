class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n=nums.size();
        long long i=0,j=0;
        //getting max
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi) maxi=nums[i];
        }
        long long ans=0;
        long long count=0;
        while(j<n){
           if(nums[j]==maxi) count++;
           while(count>=k){
            ans+=(n-j);
            if(nums[i]==maxi) count--;
            i++;
            // if(count<k) j++;
           }
           j++;
        }
        return ans;
    }
};