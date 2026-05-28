// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int sum=0;
        int temp=n;
        
        while(n>0){
            int digit=n%10;
            n/=10;
            sum+=pow(digit,3);
        }
        // cout<<sum<<" "<<n<<endl;
        return sum==temp;
    }
};