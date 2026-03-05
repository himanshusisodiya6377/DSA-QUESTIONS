class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        unordered_map<char,char>mp;
        unordered_set<char>st;

        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[i]) {
                cout<<i<<"yes"<<endl;
                return false;
            }
            else if(st.count(t[i]) && mp[s[i]]!=t[i]) return false;
            else {
                mp[s[i]]=t[i];
                // mp[t[i]]=s[i];
                st.insert(t[i]);
            }
        }
        return true;
    }
};