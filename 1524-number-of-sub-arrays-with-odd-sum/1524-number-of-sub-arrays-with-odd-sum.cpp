class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int m=(int)1e9+7;
        vector<int>sum(n,0);
        sum[0]=arr[0];
        for(int i=1;i<n;i++){
            sum[i]=(arr[i]+sum[i-1]);
        }
        int odd=0,even=0;
        for(int i=0;i<n;i++){
            if(sum[i]%2==0) even=(even+1)%m;
            else odd=(odd+1)%m;
        }
        //  odd = odd%m + (even%m * odd%m)%m;
        odd = (odd % m + (int64_t(even) % m * int64_t(odd) % m) % m) % m;

         return odd%m;
    }
};