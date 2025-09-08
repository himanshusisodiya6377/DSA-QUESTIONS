class Solution {
public:
    bool check(string ans){
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='0') return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int hf=(n/2);
        int sf=n-hf;
        while(check(to_string(hf))==false || check(to_string(sf))==false){
            hf++;
            sf--;
        }
        return {hf,sf};
    }
};