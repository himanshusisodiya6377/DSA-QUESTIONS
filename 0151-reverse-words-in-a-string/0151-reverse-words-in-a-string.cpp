class Solution {
public:
    string reverseWords(string s) {
      vector<string>v;
      string ans="";
      for(int i=0;i<s.length();i++){
        if(s[i]!=' ') ans.push_back(s[i]);
        else {
           if(ans!="") v.push_back(ans);
            ans="";
      }  
      }
        if(ans!="") v.push_back(ans);
    //   for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<endl;
    //   }
      ans="";
      for(int i=v.size()-1;i>=0;i--){
          ans+=v[i];
          if(i!=0) ans+=" ";
      } 
      return ans;
    }
};