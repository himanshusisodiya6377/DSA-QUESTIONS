class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        if(n==1 || n==2) return s;
        string ans="";
        ans.push_back(s[0]);
        for(int i=1;i<n-1;i++){
            if(s[i]==s[i-1] && s[i]==s[i+1]){
                continue;
            }
            else ans.push_back(s[i]);
        }
        ans.push_back(s[n-1]);
        return ans;
    }
};