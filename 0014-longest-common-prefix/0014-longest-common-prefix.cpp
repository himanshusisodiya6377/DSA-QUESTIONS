class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        if(strs.size()==1) return strs[0];
        string s=strs[0];
        string t=strs[strs.size()-1];
        string ans="";
        for(int i=0;i<min(s.length(),t.length());i++){
        if(s[i]==t[i]) ans.push_back(s[i]);
        else break;
    }
        return ans;
    }
};