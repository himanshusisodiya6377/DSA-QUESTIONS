class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            sum=sum%k;
            if(mp.find(sum)!=mp.end() && i-mp[sum]>=2) return true;
            if(mp.find(sum)==mp.end()) mp[sum]=i; 
        }

        return false;
    }
};