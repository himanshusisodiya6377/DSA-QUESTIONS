class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        unordered_set<string>st;

        int i=0,j=k-1;
        
        while(j<n){
            st.insert(s.substr(i,j-i+1));
            i++;
            j++;
        }

        return st.size()==pow(2,k);
    }
};