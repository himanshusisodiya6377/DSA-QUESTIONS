class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>fir(26,0);
        vector<int>sec(26,0);
        int n=s1.length();
        int m=s2.length();
        for(int i=0;i<n;i++){
            fir[s1[i]-'a']++;
        }
        int k=n;
        for(int i=0;i<k;i++){
            sec[s2[i]-'a']++;
        }
        int i=0,j=k-1;
        while(j<m-1){
           if(sec==fir) return true;
           sec[s2[i]-'a']--;
           i++;
           j++;
           sec[s2[j]-'a']++;
        }
        return false;
    }
};