class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.length();
        int num=0;
        for(auto it : s){
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u') num++;
        }
        if(num%2!=0) return true;
        if(num%2==0 && num!=0) return true;
        return false;
    }
};