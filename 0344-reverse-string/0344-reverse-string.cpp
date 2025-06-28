class Solution {
public:
    // void reversestring(vector<char>&s,int i,int j){
    //     if(i>j) return;
    //     swap(s[i],s[j]);
    //     reversestring(s,i+1,j-1);
    // }
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0,j=n-1;
         while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
         }
    }
};