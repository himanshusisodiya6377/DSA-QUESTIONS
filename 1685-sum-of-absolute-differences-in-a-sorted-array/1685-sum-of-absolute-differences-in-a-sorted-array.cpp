class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(int j=n-2;j>=0;j--){
            suff[j]=suff[j+1]+nums[j];
        }
        for(int i=0;i<n;i++){
            int prev=abs(pre[i]-nums[i]*(i+1));
            int next=suff[i]-nums[i]*(n-i);
            ans[i]=prev+next;
        }
        return ans;
    }
};