class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n=s.length();
        int ans=0;
        
        vector<int>freq(26,0);


        for(int i=0;i<n;i++){
            freq.assign(26,0);
            for(int j=i;j<n;j++){
                 freq[s[j]-'a']++;
                 for(int m=0;m<26;m++){
                    if(freq[m]>=k){
                        ans++;
                        break;
                    }
                 }
            }
        }
        return ans;
    }
};