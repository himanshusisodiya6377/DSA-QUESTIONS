class Solution {
public:
    string defangIPaddr(string address) {
        int n=address.length();
        stringstream ss(address);
        string words="";
        string ans="";
        while(getline(ss,words,'.')){
            ans+=words;
            ans+="[.]";
        }
        ans=ans.substr(0,ans.length()-3);
        return ans;
    }
};