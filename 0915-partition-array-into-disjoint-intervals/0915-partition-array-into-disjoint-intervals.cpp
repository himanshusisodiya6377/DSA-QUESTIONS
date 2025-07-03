class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++) pre[i]=max(nums[i],pre[i-1]);
        // vector<int>premin(n,0);
        // premin[0]=nums[0];
        // for(int i=1;i<n;i++) premin[i]=min(nums[i],premin[i-1]);
        vector<int>suff(n,0);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) suff[i]=min(nums[i],suff[i+1]);
        for(int i=0;i<n-1;i++){
            if(pre[i]<=suff[i+1]){
                return i+1;
            }
        }
        return 1;
    }
};