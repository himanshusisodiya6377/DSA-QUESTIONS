class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.length();
        int i=0;
        int count=1,max=0;
        for(int j=1;j<n;j++){
            if(s[j]>s[j-1]) count++;
            else{
                if(count>max) {
                    max=count;
                    count=1;
                }
                else{
                  count=1;
                }
            }
        }
        if(count>max) max=count;
        return max;
    }
};