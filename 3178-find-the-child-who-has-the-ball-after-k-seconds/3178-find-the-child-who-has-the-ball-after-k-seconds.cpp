class Solution {
public:
    int numberOfChild(int n, int k) {
              int dir=k/(n-1);

        if(dir%2==0){
            int rem=k%(n-1);
            return rem;
        }
        else {
            int rem=k%(n-1);
            return n-rem-1;
        }
        return 0;
    }
};