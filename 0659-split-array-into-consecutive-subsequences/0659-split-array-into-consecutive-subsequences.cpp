class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        int i=0;
        unordered_map<int,int>dm;
        while(i<n){
            if(mp[nums[i]]==0) {
                i++;
                continue;
            }
            else if(dm.find(nums[i])!=dm.end() && dm[nums[i]]!=0){
                dm[nums[i]]--;
                mp[nums[i]]--;
                dm[nums[i]+1]++;
                i++;
            }
            else{
                if(mp[nums[i]]==0 || mp[nums[i]+1]==0 || mp[nums[i]+2]==0) return false;
                else{
                    mp[nums[i]]--;
                    // if(mp[nums[i]]==0) mp.erase(nums[i])
                    mp[nums[i]+1]--;
                    mp[nums[i]+2]--;
                    dm[nums[i]+3]++;
                    i++;
                }
            }
        }
        return true;
    }
};