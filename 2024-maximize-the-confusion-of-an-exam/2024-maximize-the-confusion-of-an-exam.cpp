class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
       int n=answerKey.length();
       int i=0,j=1;
       int maxi=INT_MIN;
       int countt=0;
       int countf=0;
       if(answerKey[0]=='T') countt++;
       else countf++;
         if(answerKey[1]=='T') countt++;
       else countf++;
       while(j<n){
         int mini=min(countf,countt);
         if(mini<=k){
            j++;
          if(answerKey[j]=='T') countt++;
          else countf++;
         }
         else{
            int diff=j-i;
            maxi=max(maxi,diff);
            i++;
          if(answerKey[i-1]=='T') countt--;
          else countf--;
         }
       }
       maxi=max(maxi,j-i);
       return maxi;
    }
};