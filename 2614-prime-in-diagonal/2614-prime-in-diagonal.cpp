class Solution {
public:
    bool prime(int n){
        if(n==1) return false;
         for(int i=2;i<sqrt(n);i++){
              if(n%i==0) return false;
         }
         return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();//rows
        int m=nums[0].size();//coloumn
        int maxp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int l=prime(nums[i][j]);
                if(l==1){
                    maxp=max(maxp,nums[i][j]);
                }
            }
        }
             for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                int l=prime(nums[i][j]);
                if(l==1){
                    maxp=max(maxp,nums[i][j]);
                }
            }
             }
            return maxp;
        }
         
};