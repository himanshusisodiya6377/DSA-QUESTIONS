
class Solution {
  public:
    void arrange(vector<long long>& arr) {
        //  code here
       long long n=arr.size();
        vector<long long>ans(n,0);
        for(long long i=0;i<n;i++){
            ans[i]=arr[arr[i]];
        }
        for(long long i=0;i<n;i++) arr[i]=ans[i];
    }
};