class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        int i=0,j=0;
        int count=0;
        while(i<n && j<m){
            int diff=(str1[i]-str2[j]);
            if(diff==-1 || diff==25){
                i++;
                j++;
                // count++;
            }
            else if(diff==0){
                i++;
                j++;
            }
            else i++;
        }
        if(j==m) return true;
        else return false;
    }
};