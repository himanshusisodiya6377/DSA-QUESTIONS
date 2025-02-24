class Solution {
public:
    int numberOfSpecialChars(string word) {
         int n=word.length();
        //we can do this in sc O(1) by using array
        unordered_map<char,int>st;
        for(int i=0;i<n;i++){
            if(word[i]>=97 && word[i]<=122) {
                st[word[i]]=i;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(word[i]>=65 && word[i]<=90){
                char ch=tolower(word[i]);
                if(st.find(ch)!=st.end()){
                   if(st[ch]<i){
                      ans++;
                   } 
                   st.erase(ch);
                  
                } 
            }
        }
        return ans;
    }
};