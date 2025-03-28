class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long n=nums.size();
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        vector<long long>suff(n,0);
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i+1];
        }
        long long mini=INT_MAX;
        long long idx=-1;
        for(int i=0;i<n;i++){
            long long x=pre[i]/(i+1);
            long long y;
            if(i!=n-1) y=suff[i]/(n-i-1);
            else y=0;
            long long diff=abs(x-y);
            if(diff<mini){
                mini=diff;
                idx=i;
            }
        }
        return idx;
    }
};