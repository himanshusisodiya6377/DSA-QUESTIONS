class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto i : nums) mp[i]++;
        while(mp.size()!=0){
            vector<int>v;
            vector<int> keysToErase;
            for(auto &p : mp){
                v.push_back(p.first);
                p.second--;
                if(p.second==0){
                     keysToErase.push_back(p.first); 
                }
            }
              for (int key : keysToErase) {
                mp.erase(key);
            }
            ans.push_back(v);
        }
        return ans;
    }
};