class Solution {
public:
    long long minEnd(int n, int x) {
        long long last=x;

        for(int i=1;i<n;i++){
            long long want=last+1;
            want=want | x;
            last=want;
        }

        return last;
    }
};