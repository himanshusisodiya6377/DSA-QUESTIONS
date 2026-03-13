class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long n=nums.size();
        long long ans=INT_MAX;

        long long sum=0;
        for(auto &it : nums) sum+=it;
        // cout<<sum<<endl;

        long long rem=sum%p;
        // cout<<rem;
        if(rem==0) return 0;
        if(sum<p) return -1;

        unordered_map<long long,long long>mp;
        mp[0]=-1;
        
        long long curr_sum=0;
        for(int i=0;i<n;i++){
           curr_sum+=nums[i];
           
           int rem_new=(curr_sum-rem)%p;
           rem_new=rem_new%p;
           
        //    if(mp.find((p-rem_new+p)%p)!=mp.end()){
            // ans=min(ans,i-mp[(p-rem_new+p)%p]);
        //    }
           if(mp.find(rem_new)!=mp.end()) ans=min(ans,i-mp[rem_new]);
           mp[curr_sum%p]=i;
        }
        if(ans==INT_MAX || ans==n) return -1;
        return ans;
    }
};