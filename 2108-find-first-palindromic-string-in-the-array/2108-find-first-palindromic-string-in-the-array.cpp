class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(equal(words[i].begin(), words[i].begin() + words[i].size() / 2, words[i].rbegin())) return words[i];
        }
        return "";
    }
};