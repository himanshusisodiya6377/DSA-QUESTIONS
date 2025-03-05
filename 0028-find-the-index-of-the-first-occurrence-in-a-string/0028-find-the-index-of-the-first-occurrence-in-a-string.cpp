class Solution {
public:
    int strStr(string haystack, string needle) {
      int n=haystack.length();
      int m=needle.size();
      for(int i=0;i<n;i++){
        if(haystack[i]==needle[0]){
            string sub=haystack.substr(i,m);
            if(sub==needle) return i;
        }
      }  
      return -1;
    }
};