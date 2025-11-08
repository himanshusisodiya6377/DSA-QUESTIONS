class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum) return "";
        string ans="";
        while(num>0){
            if(sum>0){
                if(sum>9){
                    ans.push_back('9');
                    sum-=9;
                    num--;
                }
                else{
                    ans+=to_string(sum);
                    sum=0;
                    num--;
                }
            }
            else{
                ans.push_back('0');
                num--;
            }
        }
        return ans;
    }
};