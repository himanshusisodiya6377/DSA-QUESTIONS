class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string words="";
        string ans="";
        int count=k;
        while(ss >> words && count>0){
             ans+=words;
             ans+=' ';
             count--;
        }
        ans=ans.substr(0,ans.length()-1);
        return ans;
    }
};