class Solution {
public:
int count(int i){
    int count=0;
    while(i>0){
        count++;
        i/=10;
    }
    return count;
}
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            int num=i;
            int digit=count(num);
            num=i;
            if(digit%2!=0) continue;
            else{
                int half=digit/2;
                int leftsum=0,rightsum=0;
                while(num>0 && half>0){
                    int x=num%10;
                    rightsum+=x;
                    num/=10;
                    half--;
                }
                while(num>0){
                    int x=num%10;
                    leftsum+=x;
                    num/=10;
                }
                if(leftsum==rightsum) ans++;
            }
        }
        return ans;
    }
};