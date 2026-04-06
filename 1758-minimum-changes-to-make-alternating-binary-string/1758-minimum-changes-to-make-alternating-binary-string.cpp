class Solution {
public:
    int minOperations(string s) {
        int op1=0;
        bool flag=false;
        for(int i=0;i<s.length();i++){
              if(s[i]=='0' && flag){
                op1++;
                flag=!flag;
              }
              else if(s[i]=='1' && !flag){
                op1++;
                flag=!flag;
              }
              else flag=!flag;
        }

        flag=true;
        int op2=0;
         for(int i=0;i<s.length();i++){
              if(s[i]=='0' && flag){
                op2++;
                flag=!flag;
              }
              else if(s[i]=='1' && !flag){
                op2++;
                flag=!flag;
              }
              else flag=!flag;
        }

        return min(op1,op2);
    }
};