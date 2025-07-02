class Solution {
public:
    int minOperations(int n) {
            int ans=0;
        if(n%2==0){
            for(int i=0;i<n/2;i++){
                int diff=n-(2*i+1);
                ans+=diff;
            }
        }
        else{
            for(int i=0;i<n/2;i++){
                int diff=(n-(2*i+1));
                ans+=diff;
            }
        }
        return ans;
    }
};