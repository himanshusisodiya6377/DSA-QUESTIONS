class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.length();
        int ans=1;
        int i=0,j=0;
        while(i<n && j<n){
            if(word[i]==word[j]) j++;
            else {
                int count=j-i;
                if(count>1) ans+=(count-1);
                i=j;
            }
        }
         int count=j-i;
        if(count>1) ans+=(count-1);
        return ans;
    }
};