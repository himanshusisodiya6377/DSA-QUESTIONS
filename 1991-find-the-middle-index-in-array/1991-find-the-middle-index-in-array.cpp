class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i+1];
        }
        for(int i=0;i<n;i++){
            if(pre[i]==suff[i]) return i;
        }
        return -1;
    }
};