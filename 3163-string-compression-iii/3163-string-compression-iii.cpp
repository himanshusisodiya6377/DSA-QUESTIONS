class Solution {
public:
    string compressedString(string word) {
        int n=word.length();
        int count=1;
        string ans="";
        for(int i=0;i<n-1;i++){
            if(word[i]==word[i+1]) count++;
            else{
                    while(count>9){
                         ans.push_back('9');
                    ans.push_back(word[i]);
                    count-=9;
                    }
                    if(count!=0){
                        ans+=to_string(count);
                        ans.push_back(word[i]);
                        count=1;
                }
            }
        }
        if(count!=0){
            while(count>9){
                         ans.push_back('9');
                    ans.push_back(word[n-1]);
                    count-=9;
                    }
                    if(count!=0){
                        ans+=to_string(count);
                        ans.push_back(word[n-1]);
                        count=1;
                    }
        }
        return ans;
    }
};