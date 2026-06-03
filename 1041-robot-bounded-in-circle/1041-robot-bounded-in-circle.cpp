class Solution {
public:
    bool isRobotBounded(string ins) {
        int n=ins.length();

        char dir='N';
        int x=0,y=0;

        for(int i=0;i<n;i++){
            if(ins[i]=='L'){
                if(dir=='N') dir='w';
                else if(dir=='E') dir='N';
                else if(dir=='S') dir='E';
                else dir='S';
            }
            else if(ins[i]=='R'){
                if(dir=='N') dir='E';
                else if(dir=='E') dir='S';
                else if(dir=='S') dir='W';
                else dir='N';
            }
            else{
                if(dir=='N') y++;
                else if(dir=='E') x++;
                else if(dir=='S') y--;
                else x--;
            }
        }

        return ((dir!='N' || (x==0 && y==0)) ? true : false);
    }
};