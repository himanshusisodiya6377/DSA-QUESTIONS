class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        //tc-O(n^2)
        // string copy = s;
        // int i = 0;
        // while (i < n - 1) {
        //     char ch = s[0];
        //     s.erase(0, 1);
        //     s.push_back(ch);
        //     if (s == copy)
        //         return true;
        //     i++;
        // }
        // return false;

        //optimised approach
        for(int i=n/2;i>0;i--){
            if(n%i==0){
                int times=n/i;
                string ans="";
                string sun=s.substr(0,i);
                while(times--){
                     ans+=sun;
                }
                if(ans==s) return true;
            }
        }
        return false;
    }
};