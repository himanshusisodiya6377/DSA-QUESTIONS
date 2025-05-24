class Solution {
public:
    bool isSubsequence(string s, string t) {
        // //nahi ho pa rha check karo yaar
        // int n = a.length();
        // int m = b.length();
        // if(a=="") return true;
        // if(b=="") return false;
        // vector<vector<int>>t(n+1,vector<int>(m+1,0));
        // for(int i=1;i<n+1;i++){
        //     for(int j=1;j<m+1;j++){
        //         if(a[i-1]==b[j-1]) t[i][j]=1+t[i-1][j-1];
        //         else t[i][j]=max(t[i-1][j],t[i][j-1]);
        //     }
        // }
        // return t[n][m]==n;
        int n=s.length();
        int m=t.length();
        int i=0,j=0;
        while(i<n && j<m){
            if(s[i]!=t[j]) j++;
            else{
                i++;
                j++;
            }
        }
        if(i>=n) return true;
        else return false;
    }
};