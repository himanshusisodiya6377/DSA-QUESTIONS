class Solution {
public:
    int partitionString(string s) {
        int n=s.length();
        unordered_set<char>st;

        int i=0,j=0;
        int ans=0;
        while(j<n){
           if(st.find(s[j])!=st.end()){
            i=j;
            st.clear();
            st.insert(s[j]);
            ans++;
           }
           else{
             st.insert(s[j]);
            //  j++;
           }
           j++;
        }

        return ans+1;
    }
};