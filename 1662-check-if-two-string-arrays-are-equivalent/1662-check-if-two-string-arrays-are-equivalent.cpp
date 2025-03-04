class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word1s="";
        string word2s="";
        for(int i=0;i<word1.size();i++) word1s+=word1[i];
         for(int i=0;i<word2.size();i++) word2s+=word2[i];
         if(word1s==word2s) return true;
         return false;
    }
};