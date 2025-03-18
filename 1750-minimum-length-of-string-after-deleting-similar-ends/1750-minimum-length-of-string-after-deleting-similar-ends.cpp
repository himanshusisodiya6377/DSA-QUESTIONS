class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]) return (j-i+1);
            else{
                char ch=s[i];
                while(i<n && s[i]==ch) i++;
                while(j>=0 && s[j]==ch) j--;
            }
        }
        if(i==j) return 1;
        return 0;
    }
};