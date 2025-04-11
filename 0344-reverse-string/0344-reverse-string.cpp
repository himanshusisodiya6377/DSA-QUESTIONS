class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            int temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }

    }
};