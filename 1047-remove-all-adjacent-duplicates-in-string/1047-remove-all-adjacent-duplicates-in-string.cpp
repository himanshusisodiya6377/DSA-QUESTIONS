class Solution {
public:
    string removeDuplicates(string s) {
     int n=s.length();
     string ans="";
     for(int i=0;i<n;i++){
        ans.push_back(s[i]);
        if(ans.size()>=2){
            if(ans[ans.size()-1]==ans[ans.size()-2]) ans.erase(ans.size()-2,2);
        }
     }   
     return ans;
    }
};