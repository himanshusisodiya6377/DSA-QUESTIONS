class Solution {
public:
    int reverseBits(int n) {
        
        int i=0;

        int x=0;

        while(i<32){
            // cout<<(n & (1<<i))<<endl;
            if((n & (1<<i))>0){
                x+=(1<<(31-i));
            }
            i++;
            // cout<<x<<" "<<i<<endl;
        }

        return x;
    }
};