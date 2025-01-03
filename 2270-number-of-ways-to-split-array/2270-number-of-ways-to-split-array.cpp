class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pre(n,0);
         vector<long long>suff(n,0);
        pre[n-1]=nums[n-1];
        suff[0]=nums[0];
        for(int i=1;i<n;i++) suff[i]+=(suff[i-1]+(long long)nums[i]);//suffix array
         for(int i=n-2;i>=0;i--) pre[i]+=(pre[i+1]+(long long)nums[i]);//pre array
         int count=0;
         for(int i=0;i<n-1;i++){
            if(suff[i]>=pre[i+1]) count++;
         }
         return count;

    }
};