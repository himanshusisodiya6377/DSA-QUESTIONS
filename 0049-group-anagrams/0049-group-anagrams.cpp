class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> v;
        // for (int i = 0; i < n; i++) {
        //     string ans = strs[i];
        //     sort(begin(ans), end(ans));
        //     mp[ans].push_back(strs[i]);
        // }
        // for (auto p : mp) {
        //     v.push_back(p.second);
        // }
        for(auto num : strs){
            vector<int>ap(26,0);
            string ans="";
            for(auto c : num) ap[c-'a']++;
            for(int i=0;i<26;i++){
                if(ap[i]!=0) ans.push_back(i+'a');
            }
            mp[ans].push_back(num);
        }
        for(auto num : mp){
            v.push_back(num.second);
        }
        return v;
    }
};