class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>fir(26,0);
        vector<int>sec(26,0);
        int n=s1.length();
        int m=s2.length();
        if(n>m) return false;
        for(int i=0;i<n;i++){
            fir[s1[i]-'a']++;
        }
        int k=n;
        for(int i=0;i<k;i++){
            sec[s2[i]-'a']++;
        }
        if(sec==fir) return true;
        int i=0,j=k-1;
        while(j<m-1){
           sec[s2[i]-'a']--;
           i++;
           j++;
           sec[s2[j]-'a']++;
           if(sec==fir) return true;
        }
        return false;
    }
};