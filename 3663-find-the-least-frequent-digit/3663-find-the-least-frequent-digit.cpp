class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string ans=to_string(n);
        sort(ans.begin(),ans.end());
        int i=0,j=0;
        int m=ans.length();
        int mini=INT_MAX;
        char ch;
        while(j<m){
            while(j<m && ans[i]==ans[j]){
                j++;
            }
            int len=(j-i)+1;
            if(len<mini){
                mini=len;
                ch=ans[i];
            }
            i=j;
        }
        return ch-48;
    }
};
