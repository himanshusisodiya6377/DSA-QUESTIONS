class Solution {
public:
    bool checkZeroOnes(string s) {
            int n=s.length(), count=0, max1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
            else{
                if(count>max1)
                    max1=count;
                    count=0;
                
            }
        }
          if(count>max1){
                    max1=count;
                }
            count=0;
            int max2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count++;
            }
            else{
                if(count>max2)
                    max2=count;
                    count=0;
                
            }
        }
          if(count>max2){
                    max2=count;
                }
            return max1>max2;
    }
};