class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        for(auto v : mp){
            if(v.second.size()>1){
                for(int i=0;i<v.second.size()-1;i++){
                if((v.second[i+1]-v.second[i])<=k) return true;
                }
            }
        }
        return false;
    }
};