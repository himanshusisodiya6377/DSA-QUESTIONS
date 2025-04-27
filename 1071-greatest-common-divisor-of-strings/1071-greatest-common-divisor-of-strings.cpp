class Solution {
public:
   int hcf(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
    string gcdOfStrings(string str1, string str2) {
         if (str1 + str2 != str2 + str1) return "";
        int len = hcf(str1.length(), str2.length());
        return str1.substr(0, len);
        // int n=str1.length();
        // int m=str2.length();
        // if(n==m){
        //     if(str1==str2) return str1;
        //     else return "";
        // }
        // int diff=hcf(n,m);
        // int i=0,j=0;
        // if(n>m){
        // while(i<n){
        //     if(str1[i]!=str2[j]) return "";
        //     i++;
        //     j++;
        //     if(j==m) j=0;
        // }
        // if(j!=0) return "";
        // }
        // else{
        //      while(j<m){
        //     if(str1[i]!=str2[j]) return "";
        //     i++;
        //     j++;
        //     if(i==n) i=0;
        // }
        // if(i!=0) return "";
        // }
        // return str1.substr(0,diff);
    }
};