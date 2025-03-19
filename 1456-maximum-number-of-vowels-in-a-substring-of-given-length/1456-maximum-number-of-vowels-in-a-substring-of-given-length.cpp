class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int count=0;
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count++;
            }
        }
        maxi=count;
        int i=0,j=k-1;
        while(j<n){
            j++;
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                count++;
            }
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count--;
            }
            i++;
            maxi=max(maxi,count);
        }
        return maxi;
    }
};