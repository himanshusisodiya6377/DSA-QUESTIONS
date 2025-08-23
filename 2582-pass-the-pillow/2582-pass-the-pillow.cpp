class Solution {
public:
    int passThePillow(int n, int time) {
        int dir=time/(n-1);

        if(dir%2==0){
            int rem=time%(n-1);
            return rem+1;
        }
        else {
            int rem=time%(n-1);
            return n-rem;
        }
        return 0;
    }
};