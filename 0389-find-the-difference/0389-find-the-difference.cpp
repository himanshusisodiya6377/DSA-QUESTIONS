class Solution {
public:
    char findTheDifference(string s, string t) {
        string ans=s+t;
        int x=0;
        for(int i=0;i<ans.length();i++){
            x^=ans[i];
        }
        char ch=(char)x;
        return ch;
    }
};