class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]].push_back(i);
        }
        int maxi = -1;
        for (auto p : mp) {
            vector<int> nums = p.second;
            int diff=nums[nums.size()-1]-nums[0]-1;
            if(diff>maxi) maxi=diff;
        }
        return maxi;
    }
};