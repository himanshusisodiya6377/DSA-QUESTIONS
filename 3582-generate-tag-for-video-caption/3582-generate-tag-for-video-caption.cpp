class Solution {
public:
    string generateTag(string caption) {
        stringstream ss(caption);
        string words;
        string ans="#";
        bool flag=false;
        int range=1;
        while(ss>>words && range<=100){
            if(flag){
              string get="";
              int ch=words[0];
              if(ch>=65 && ch<=90){
                get.push_back(char(ch));
              }
              else{
                int ch=words[0]-32;
                get.push_back(char(ch));
              }
              int size;
              if(words.length()<100) size=words.length();
              else size=100;
              for(int i=1;i<size;i++){
                    int ch=words[i];
              if(ch>=65 && ch<=90){
                ch+=32;
                get.push_back(char(ch));
              }
              else{
                get.push_back(char(ch));
              } 
              }
              if(range+get.length()<=100){
              ans+=get;
              range+=get.length();
              }
            }
            else{
                string get="";
                  int ch=words[0];
              if(ch>=65 && ch<=90){
                ch+=32;
                get.push_back(char(ch));
              }
              else{
                get.push_back(char(ch));
              }
               int size;
              if(words.length()<100) size=words.length();
              else size=99;
            for(int i=1;i<size;i++){
                    int ch=words[i];
              if(ch>=65 && ch<=90){
                ch+=32;
                get.push_back(char(ch));
              }
              else{
                get.push_back(char(ch));
              } 
              }
            if(range+get.length()<=100){
              ans+=get;
              range+=get.length();
              }
                flag=true;
            }
        }
       return ans;
    }
};