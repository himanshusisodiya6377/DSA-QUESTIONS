class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        vector<int>prevow(s.length(),0);
        vector<int>precon(s.length(),0);
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                prevow[i]++;
            }
            else precon[i]++;
        }
        int count=0;
        for(int i=0;i<s.length();i++){
            int lengthvow=0;
            int lengthcon=0;
            for(int j=i;j<s.length();j++){
                if(prevow[j]!=0) lengthvow+=prevow[j];
                else lengthcon+=precon[j];
                if(lengthvow==lengthcon){
                    int prod=lengthvow*lengthcon;
                    if(prod%k==0) count++;
                }
            }
        }
        return count;
    }
};