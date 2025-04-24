class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
       int n=nums.size();
       unordered_map<int,int>mp;
       for(auto v : nums){
        mp[v]++;
       }
       int uniq=mp.size();
       if(uniq==1){
        return (mp[nums[0]]*(mp[nums[0]]+1))/2;
       }
       int i=0,j=0;
       unordered_map<int,int>uq;
       int ans=0;
       uq[nums[j]]++;
       while(j<n){
        if(uq.size()!=uniq){
            j++;
            if(j>=n) break;
            uq[nums[j]]++;
            // if(uq.size()==uniq) j--;
        }
        else{
            ans+=n-j;
             uq[nums[i]]--;
            if(uq[nums[i]]==0) uq.erase(nums[i]);
            i++;
           
        }
       }
       return ans;
    }
};