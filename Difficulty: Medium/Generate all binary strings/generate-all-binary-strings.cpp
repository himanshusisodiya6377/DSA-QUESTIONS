class Solution {
  public:
  
    void solve(string s,int idx,vector<string>&ans){
             if(idx>=s.length()){
                 ans.push_back(s);
                 return;
             }    
             ans.push_back(s);
             for(int i=idx;i<s.length();i++){
                 s[i]='1';
                 solve(s,i+1,ans);
                 s[i]='0';
             }
    }
    
    vector<string> binstr(int n) {
        // code here
        vector<string>ans;
        string s;
        for(int i=0;i<n;i++) s+="0";
        // cout<<s.size();
        ans.push_back(s);
        for(int i=0;i<n;i++){
            s[i]='1';
            solve(s,i+1,ans);
            s[i]='0';
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};