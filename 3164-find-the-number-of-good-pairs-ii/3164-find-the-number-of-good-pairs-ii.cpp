class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         int cnt=0;
        
         unordered_map<int,int>mp;

         for(auto it : nums2){
            mp[it]++;
         }

         for(auto it :  nums1){
            if(it%k!=0) continue;

            for(int i=1;i*i<=it;i++){
                int fac1=i,fac2=it/i;
                cnt+=mp[fac1];
                if(fac1!=fac2) cnt+=mp[fac2];
            }
         }
        

        return cnt;
    }
};