class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        for(int i=0;i<s.length();i++){
            mp[t[i]]-=i;
        }
        int ans=0;
        for(auto p : mp){
          ans+=abs(p.second);
        }
        return ans;
    }
};