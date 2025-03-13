class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>sum(n,0);
        sum[0]=arr[0];
        for(int i=1;i<n;i++){
            sum[i]=arr[i]+sum[i-1];
        }
        int odd=0,even=0;
        for(int i=0;i<n;i++){
            if(sum[i]%2==0) even++;
            else odd++;
        }
        return odd+(odd*even);
    }
};