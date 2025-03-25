class Solution {
public:

    int minimizeXor(int num1, int num2) {
        int cnt=__builtin_popcount(num2);
        int ans=0;
        for(int i=31;i>=0 && cnt>0;i--){
            int temp=num1&(1<<i);
            if(temp!=0){
                ans|=(1<<i);
                cnt--;
            }
        }
        for(int i=0;i<32 && cnt>0;i++){
            int temp=num1&(1<<i);
            if(temp==0){
                ans|=(1<<i);
                cnt--;
            }
        }
        return ans;
    }
};