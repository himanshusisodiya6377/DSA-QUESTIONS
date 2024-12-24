class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        // int n=nums.size();
        // int max=nums[0];
        // vector<long long>v;
        // long long int pre[n];
        // pre[0]=2*nums[0];
        // v.push_back(pre[0]);
        // for(int i=1;i<n;i++){
        //        if(max<nums[i]) max=nums[i];
        //     pre[i]=nums[i]+max+pre[i-1];
        //      v.push_back(pre[i]);
        // }
        // return v;
        int n=nums.size();
        vector<long long>v(n,0);
        int maxi=nums[0];
        v[0]=maxi+nums[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi,nums[i]);
            v[i]+=(v[i-1]+maxi+nums[i]);
        }
       return v;
    }
};