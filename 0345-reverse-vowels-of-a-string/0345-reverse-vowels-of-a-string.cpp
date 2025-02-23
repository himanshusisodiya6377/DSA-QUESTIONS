class Solution {
public:
    string reverseVowels(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            char x=s[i];
            char y=s[j];
            if((x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U') && (y=='a' || y=='e' || y=='i' || y=='o' || y=='u' || y=='A' || y=='E' || y=='I' || y=='O' || y=='U')){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U') j--;
            else i++;
        }
        return s;
    }
};