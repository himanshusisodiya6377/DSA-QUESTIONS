class Solution {
public:
    int countCommas(int n) {

        if(n<1000) return 0;
        int low=1000;
        // cout<<high;
        return n-low+1;
    }
};