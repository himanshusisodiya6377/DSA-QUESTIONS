class Solution {
public:
    int minFlips(string s) {
        string t=s+s;
        int n=s.length();
        vector<int>preA(2*n,0); //01010101
        vector<int>preB(2*n,0);  //10101010
        (s[0]=='0' ? preA[0]=0  : preA[0]=1);
        (s[0]=='1' ? preB[0]=0  : preB[0]=1);
        for(int i=1;i<2*n;i++){
            if(i%2==0){
               preA[i]=preA[i-1]+(t[i]=='0' ? 0 : 1);
               preB[i]=preB[i-1]+(t[i]=='1' ? 0 : 1);
            }
            else{
               preA[i]=preA[i-1]+(t[i]=='1' ? 0 : 1);
               preB[i]=preB[i-1]+(t[i]=='0' ? 0 : 1);
            }
        }
        
        // for(auto it : preA) cout<<it<<" ";
        // cout<<endl;
        // for(auto it : preB) cout<<it<<" ";
        
        int i=1,j=n;
        int mini=min(preA[n-1],preB[n-1]);

        while(i<n){
            mini=min(mini,min(preA[j]-preA[i-1],preB[j]-preB[i-1]));
            i++;
            j++;
        }
        return mini;
    }
};