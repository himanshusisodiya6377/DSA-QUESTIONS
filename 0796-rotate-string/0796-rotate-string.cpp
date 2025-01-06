class Solution {
public:
    bool rotateString(string s, string goal) {
       int n=s.size();
       if(s.size()!=goal.size()) return false;
       while(n>0){
        if(s==goal) return true;
        char ch=s[0];
        s.erase(s.begin());
        s.push_back(ch);
        if(s==goal) return true;
        n--;
       }
      return false;
    }
};