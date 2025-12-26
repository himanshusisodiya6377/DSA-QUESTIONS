class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int ans=1;
        long long sum=0;
        while(j<n){
            sum+=nums[j];
            // (j!=0 ? k-=((j-i)*(nums[j]-nums[j-1])): 0);
            while(i<=j && (long long)nums[j] * (j - i + 1) - sum > k){
               sum-=nums[i];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        // ans=max(ans,j-i+1);
        return ans;
    }
};