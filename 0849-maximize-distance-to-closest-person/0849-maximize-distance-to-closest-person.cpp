class Solution {
public:
    int maxDistToClosest(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        vector<int>suff(n,0);

        for(int i=0;i<n;i++){
            if(nums[i]==1) pre[i]=i;
            else if(i==0) pre[i]=-1;
            else pre[i]=pre[i-1];
        }

        for(int i=n-1;i>=0;i--){
            if(nums[i]==1) suff[i]=i;
            else if(i==n-1) suff[i]=n;
            else suff[i]=suff[i+1];
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(i==0) ans=max(ans,suff[i]-i);
            else if(i==n-1) ans=max(ans,i-pre[i]);
            else{
                ans=min(max(ans,(pre[i]!=-1 ? i-pre[i] :0)),max(ans,(suff[i]!=n ? suff[i]-i : 0)));
            }

            // cout<<ans<<" "<<i<<endl;
        }

        return ans;
    }
};