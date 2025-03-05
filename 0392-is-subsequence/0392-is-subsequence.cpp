class Solution {
public:
    bool isSubsequence(string s, string t) {
      int n=s.length();
      int m=t.length();
      if(n==0) return true;
     int index=0;
     for(int i=0;i<m;i++){
        if(t[i]==s[0]){
          index=i;
          break;
        } 
     }
     int count=0;
     int j=0;
     for(int i=index;i<m;i++){
          if(s[j]==t[i]){
            count++;
            j++;
          }
     }
     if(count==n) return true;
     else return false;
    }
};