class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n=s.length();
        vector<int>v(n,0);
        int prev=0;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                prev++;
                v[i]=prev;
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=v[i];
        }
        return ans;
    }
};