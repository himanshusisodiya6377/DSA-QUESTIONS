class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>v(26,0);
        vector<bool>boo(26,false);
        int n=s.length();
        for(int i=0;i<n;i++) v[s[i]-'a']++;
        int i=1;
        string ans="";
        ans.push_back(s[0]);
        boo[s[0]-'a']=true;
        while(i<n){
            if(ans.size()==0) ans.push_back(s[i]);
            while(ans.size()>0 && ans.back()>s[i] && v[ans.back()-'a']>1 && boo[s[i]-'a']==false){              
                 char ch=ans.back();
                ans.pop_back();
                v[ch-'a']--;
                boo[ch-'a']=false;
            }
            if(boo[s[i]-'a']==false){
                 ans.push_back(s[i]);
            boo[s[i]-'a']=true;
            i++;
            }
           else{
            v[s[i]-'a']--;
            i++;
              
           } 
        }
      return ans;
    }
};