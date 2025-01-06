class Solution {
public:
    bool rotateString(string s, string goal) {
        int idx=-1;
        for(int i=0;goal[i]!='\0';i++){
            if(s[0]==goal[i]) {
                idx=i;
                break;
            }
        }
        string sub1=goal.substr(0,idx);
         string sub2=goal.substr(idx);
          string sub3=sub2+sub1;
          if(sub3==s) return true;
          else return false;

    }
};