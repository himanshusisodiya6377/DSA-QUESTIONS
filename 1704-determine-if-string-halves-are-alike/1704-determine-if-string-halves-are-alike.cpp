class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int countfirst=0;
        int countsec=0;
        for(int i=0;i<n/2;i++){
            char ch=tolower(s[i]);
          if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') countfirst++;
        
    }
     for(int i=n/2;i<n;i++){
            char ch=tolower(s[i]);
          if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') countsec++;
        }
        if(countfirst==countsec) return true;
        return false;
    }
};