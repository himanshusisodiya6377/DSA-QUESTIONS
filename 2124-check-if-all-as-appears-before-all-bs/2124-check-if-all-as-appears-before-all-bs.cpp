class Solution {
public:
    bool checkString(string s) {
     string cpy=s;
     sort(s.begin(),s.end());
     for(int i=0;i<s.length();i++){
        if(s[i]!=cpy[i]) return false;
     }   
     return true;
    }
};