class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda=[](int &a,int &b){
            int counta=__builtin_popcount(a);
            int countb=__builtin_popcount(b);
            if(counta==countb){
                return a<b;
            }
            else return counta<countb;
        };
        sort(arr.begin(),arr.end(),lambda);
        return arr;
    }
};