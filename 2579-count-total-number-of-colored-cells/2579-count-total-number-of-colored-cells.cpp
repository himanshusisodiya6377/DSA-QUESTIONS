class Solution {
public:
    long long coloredCells(int n) {
        long long sq=(long long)n*n;
        long long ans=2*sq-2*n+1;
        return ans;
    }
};