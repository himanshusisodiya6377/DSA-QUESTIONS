class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans="";
        int n=s.length();
        int m=part.size();
        for(int i=0;i<n;i++){
            ans.push_back(s[i]);
            if(ans.size()>=m){
              string check=ans.substr(ans.size()-m,m);
              if(check==part){
                ans.erase(ans.size()-m,m);
              }
            }
        }
        return ans;
    }
};