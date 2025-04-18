class Solution {
public:
    int lcs(string word1,string word2,int n,int m){
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[i-1]==word2[j-1])
                t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[n][m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(word1==word2) return 0;
        return m+n-2*lcs(word1,word2,n,m);
    }
};