class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     int n=strs.size();
     unordered_map<string,vector<string>>mp;
     vector<vector<string>>v;
     for(int i=0;i<n;i++){
        string ans=strs[i];
        sort(begin(ans),end(ans));
        mp[ans].push_back(strs[i]);
     }
     for(auto p : mp){
        v.push_back(p.second);
     }  
     return v;
    }
};