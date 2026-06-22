class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long n=nums.size();

        vector<long long>pre(n,0);
        pre[0]=nums[0];

        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];

        long long ans=0;
        long long cnt=0;
        // if(s[0]=='1') ans+=nums[0];
        long long prev=0;
        for(int i=0;i<n;i++){
           if(s[i]=='0'){
            if(cnt!=0){
                ans+=prev;
            }
            cnt=0;
            continue;
           }
           else{
            cnt++;
              long long curr_sum=pre[i]-(i-cnt>=0 ? pre[i-cnt] : 0);
             long long prev_sum=(i-1>=0 ? pre[i-1] : 0)-(i-cnt-1>=0 ? pre[i-cnt-1] : 0);
             if(prev_sum>curr_sum){
                ans+=prev_sum;
                cnt=0;
             }
             prev=curr_sum;
           }
        }   
        if(s[n-1]=='1'){
            long long i=n-1;
            long long curr_sum=pre[i]-(i-cnt>=0 ? pre[i-cnt] : 0);
             long long prev_sum=(i-1>=0 ? pre[i-1] : 0)-(i-cnt-1>=0 ? pre[i-cnt-1] : 0);
            //  cout<<curr_sum<<" "<<prev_sum<<endl;
             if(prev_sum>curr_sum){
                ans+=prev_sum;
                cnt=0;
             }
        }
        // cout<<cnt<<" "<<prev;

        if(cnt!=0){
            ans+=prev;
        }

        return ans;
    }
};