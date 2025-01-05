class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        int siz=shifts.size();
        vector<long long>ans(siz,0);
        ans[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]=ans[i+1]+shifts[i];
        }
        int carry=0;
        for(int i=0;i<siz;i++){
            long long inc=ans[i];
            while(inc>26){
                inc=inc%26;
            }
                long long x=s[i];
                x+=inc;
                while(x>122){
                carry=x%122;
                x=96+carry;
                }
                char ch=(char) x;
                s[i]=ch;
            }
        
       return s;
    }
};