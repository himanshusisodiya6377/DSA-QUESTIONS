class Solution {
public:
    int maxPower(string s) {
        int i=0;
        int count=0,max=0;
        for(int j=0;j<s.length();j++){
             if(s[j]==s[i]) count++;
             else{
                if(max<count) max=count;
                i=j;
                count=1;
             }
        }
        if(count>max) max=count;
        return max;
    }
};