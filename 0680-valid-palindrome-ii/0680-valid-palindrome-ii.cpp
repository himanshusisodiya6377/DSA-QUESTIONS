class Solution {
public:
    bool solve(string s){
        //  bool flag=false;
        int n=s.length();
        int i=0,j=n-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
           else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        // bool flag=false;
        int n=s.length();
        int i=0,j=n-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                if(s[i]==s[j-1]){
                   cout<<s.substr(i,j-i)<<endl;
                   if(solve(s.substr(i,j-i))) return true;
                //    state=false;
                }
                if(s[j]==s[i+1]){
                    // state=true;
                   if(solve( s.substr(i+1,j-i))) return true;
                }
                return false;
            }
        }
        return true;
    }
};