class Solution {
public:
    int minOperations(int k) {
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            int opr=0;
            //make it equal to i 
            opr+=(i-1);

            //appending the i
            int diff=k-i;
            int req_opr=((diff+i-1)/i);
            // cout<<req_opr<<endl;

            opr+=req_opr;
            ans=min(ans,opr);
            // cout<<i<<" "<<opr<<" "<<ans<<endl;
        }

        return ans;
    }
};