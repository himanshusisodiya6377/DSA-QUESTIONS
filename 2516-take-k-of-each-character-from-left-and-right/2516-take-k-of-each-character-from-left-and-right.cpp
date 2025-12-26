class Solution {
public:
    int solve(string &s,vector<int>&mp){
        int n=s.length();
        int i=0,j=0;
        int len=0;
        vector<int>freq(3,0);
        while(j<n){
            freq[s[j]-'a']++;
            while(i<=j && (freq[0]>mp[0] || freq[1]>mp[1] || freq[2]>mp[2])){
                freq[s[i]-'a']--;
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        cout<<len<<endl;
        return len;
    }
    int takeCharacters(string s, int k) {
        vector<int>mp(3,0);
        int n=s.length();
        for(auto &it : s){
            mp[it-'a']++;
        }
        for(auto &it : mp) 
             if(it==0 && k!=0) return -1;
        for(int i=0;i<3;i++) {
            if (mp[i]-k < 0 ) return -1;
            else  mp[i]-=k;
        }
        // int ans=
        return n-solve(s,mp);
    }
};