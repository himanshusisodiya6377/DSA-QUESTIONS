class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=chalk[i];
        k%=sum;
        int i=0;
        while(k>=0){
           k-=chalk[i];
           if(k<0){
            return i;
           }
           i++;
        }
        // if(k<0) return n-1;
        return 0;
    }
};