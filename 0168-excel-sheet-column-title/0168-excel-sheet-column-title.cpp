class Solution {
public:
    string convertToTitle(int num) {
        string ans="";
        while(num>0){
            num--;
            int digit=(num)%26;
            // digit--;
            num/=26;
            ans.push_back('A'+digit);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};