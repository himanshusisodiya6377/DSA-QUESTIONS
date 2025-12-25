class Solution {
public:
    int solve(vector<int>&num,int k){
        int n=num.size();
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int>mp;
        int cnt=0;
        while(j<n){
            mp[num[j]]++;
            if(mp[num[j]]==1) cnt++;
            while(i<=j && cnt>k){
            mp[num[i]]--;
            if(mp[num[i]]==0) cnt--;
            i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};