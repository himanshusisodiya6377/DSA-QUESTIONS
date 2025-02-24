class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int capital=0;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(word[i]>=65 && word[i]<=90) {
                capital++;
                idx=i;
            }
        }
        if(capital==n || (capital==1 && idx==0) || capital==0) return true;
        else return false;
    }
};