class Solution {
public:
    string s="0";
    string invert(string temp){
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='0') temp[i]='1';
            else temp[i]='0';
        }
        return temp;
    }
    char findKthBit(int n, int k) {
        if(n==1){
            // cout<<s<<endl;
            return s[k-1];
        }
       
        string temp=s;
        reverse(temp.begin(),temp.end());
        temp=invert(temp);
        s=s+"1"+temp;
        return findKthBit(n-1,k); 
    }
};