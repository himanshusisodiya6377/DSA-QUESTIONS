class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>st;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            st[s[j]]++;
            while(i<=j && st[s[j]]!=1){
                st[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};