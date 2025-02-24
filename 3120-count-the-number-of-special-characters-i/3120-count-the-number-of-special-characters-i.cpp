class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            if(word[i]>=97 && word[i]<=122) st.insert(word[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(word[i]>=65 && word[i]<=90){
                char ch=tolower(word[i]);
                if(st.find(ch)!=st.end()){
                   ans++;
                   st.erase(ch);
                } 
            }
        }
        return ans;
    }
};