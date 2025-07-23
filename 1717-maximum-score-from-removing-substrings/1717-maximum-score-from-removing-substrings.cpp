class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        int ans=0;
        if(y>=x){
        string temp="";
        for(int i=0;i<n;i++){
            if(temp.length()==0) temp.push_back(s[i]);
            else{
                char ch=temp[temp.length()-1];
                if(ch=='b' && s[i]=='a'){
                    ans+=y;
                    temp.pop_back();
                }
                else temp.push_back(s[i]);
            }
        }
    
        string check="";
     
       for(int i=0;i<temp.length();i++){
         if(check.length()==0) check.push_back(temp[i]);
            else{
                char ch=check[check.length()-1];
                if(ch=='a' && temp[i]=='b'){
                    ans+=x;
                    check.pop_back();
                }
                else if(ch=='b' && temp[i]=='a'){
                    ans+=y;
                    check.pop_back();
                }
                else check.push_back(temp[i]);
            }
       }
        }///////////
        else{
            string temp="";
        for(int i=0;i<n;i++){
            if(temp.length()==0) temp.push_back(s[i]);
            else{
                char ch=temp[temp.length()-1];
                if(ch=='a' && s[i]=='b'){
                    ans+=x;
                    temp.pop_back();
                }
                else temp.push_back(s[i]);
            }
        }
    
        string check="";
     
       for(int i=0;i<temp.length();i++){
         if(check.length()==0) check.push_back(temp[i]);
            else{
                char ch=check[check.length()-1];
                if(ch=='b' && temp[i]=='a'){
                    ans+=y;
                    check.pop_back();
                }
                else if(ch=='a' && temp[i]=='b'){
                    ans+=x;
                    check.pop_back();
                }
                else check.push_back(temp[i]);
            }
       }
        }
        return ans;
    }
};