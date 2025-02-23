class Solution {
public:
    bool makeEqual(vector<string>& words) {
       int n=words.size();
       if(n==1) return true;
       string ans="";
       for(int i=0;i<n;i++){
        ans+=words[i];
       } 
       unordered_map<char,int>mp;
       for(int i=0;i<ans.length();i++){
        mp[ans[i]]++;
       }
       for(auto p : mp){
        if(p.second %n!=0) return false;
       }
       return true;
    }
};