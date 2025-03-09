class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(freq[i]%2==0 && freq[i]!=0) ans+=2;
            else if(freq[i]%2!=0) ans+=1;
        }
        return ans;
    }
};