class Solution {
public:
    unordered_map<char,string>mp;
    vector<string>ans;
    bool flag=false;
    void intialize(){
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        flag=true;
    }
    void solve(string digit,string s,int idx){
        if(idx>=digit.length()){
            ans.push_back(s);
            // cout<<s<<endl;
            return;
        }

        for(int i=0;i<mp[digit[idx]].length();i++){
            s.push_back(mp[digit[idx]][i]);
            solve(digit,s,idx+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digit) {
        if(!flag) intialize();
        solve(digit,"",0);
        return ans;
    }
};