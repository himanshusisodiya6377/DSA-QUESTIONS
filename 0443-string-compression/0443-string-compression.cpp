class Solution {
public:
    int compress(vector<char>& chars) {
       int count=1;
       int n=chars.size();
       int index=0,i=0;
       char ch;
       while(i<n){
        ch=chars[i];
        i++;
        while(i<n && chars[i]==ch){
            count++;
            i++;
        }
        chars[index]=ch;
        index++;
        if(count>1){
            string num=to_string(count);
            for(char &no : num){
                chars[index]=no;
                index++;
            }
            count=1;
        }
       }
       return index;
    }
};