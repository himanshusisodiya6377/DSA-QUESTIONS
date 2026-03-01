class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp; //val freq
        for(auto &it : nums) mp[it]++;
        // if(mp.size()==1) return -1;

        unordered_map<int,int>sz;
        for(auto &it : mp){
            sz[it.second]++;
        }

        for(auto &it : nums){
            int freq=mp[it];
            if(sz[freq]==1) return it;
        }

        return -1;
    }
};