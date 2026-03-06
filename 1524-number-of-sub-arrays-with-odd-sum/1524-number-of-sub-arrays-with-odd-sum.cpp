class Solution {
public:
    int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        
        unordered_map<int,int>mp;
        long long sum=0;
        long long cnt=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
               cnt+=mp[1];
               cnt=cnt%mod;
            }
            else{
               cnt+=mp[0];
               cnt++;
               cnt=cnt%mod;
            }
            mp[sum%2]++;
        }
        return cnt%mod;
    }
};