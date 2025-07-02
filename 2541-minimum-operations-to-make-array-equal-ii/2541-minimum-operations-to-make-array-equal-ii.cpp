class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
         long long n=nums1.size();
        vector< long long>v(n,0);
        if(nums1==nums2) return 0;
        if(k==0) return -1;
        for( long long i=0;i<n;i++) v[i]=nums2[i]-nums1[i];
         long long sum=0;
         long long cnt=0;
        for( long long i=0;i<n;i++) sum+=v[i];
        if(sum!=0) return -1;
        else{
            for( long long i=0;i<n;i++){
                if(v[i]%k==0){
                    cnt+=abs(v[i]/k);
                }
                else return -1;
            }
        }
        return cnt/2;
    }
};