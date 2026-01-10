class Solution {
  public:
    int solve(string &s,int k){
        int n=s.length();
        int i=0,j=0;
        int ans=0;
        // unordered_map<char,int>mp;
        vector<int>freq(26,0);
        int need=0;
        while(j<n){
            freq[s[j]-'a']++;
            if(freq[s[j]-'a']==1) need++;
            while(i<=j && need>k){
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0) need--;
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here
        return solve(s,k)-solve(s,k-1);
    }
};