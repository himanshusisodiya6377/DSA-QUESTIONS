class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        // if(n%2!=0) return false;
        // int m=n/2;
        // string s1=s.substr(0,m);
        // string s2=s.substr(m,m);
        // if(s1==s2) return true;
        // else return false;
        string copy=s;
        int i=0;
        while(i<n-1){
            char ch=s[0];
            s.erase(0,1);
            s.push_back(ch);
            if(s==copy) return true;
            i++;
        } 
        return false;
    }
};