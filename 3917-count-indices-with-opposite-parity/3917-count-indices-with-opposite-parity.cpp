class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);

        unordered_map<int,int>mp;

        for(int i=n-1;i>=0;i--){
            if(nums[i]%2==0) ans[i]=mp[1];
            else ans[i]=mp[0];
            mp[nums[i]%2]++;
        }

        return ans;
    }
};