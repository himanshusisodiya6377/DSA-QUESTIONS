class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0,j=0;
        int maxi=0;
        unordered_set<char>st;
        while(j<n){
           if(st.find(s[j])==st.end()){
            st.insert(s[j]);
            j++;
           }
           else{
                maxi=max(maxi,j-i);
                st.erase(s[i]);
                i++;
           }
        }
        maxi=max(maxi,j-i);
        return maxi;
    }
};