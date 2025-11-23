class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        string temp="";
       
        long long sum=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                temp.push_back(s[i]);
                sum+=s[i]-48;
            }
        }
         if(temp.size()==0) return 0;
        // cout<<temp<<endl;/
        // cout<<sum<<endl;
        // cout<<stoi(temp)<<endl;
        return stoi(temp)*sum;
    }
};