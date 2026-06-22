class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        vector<int>ans(queries.size(),0);

        vector<int>pre(n,0);
        pre[0]=1;
        pre[n-1]=n-2;

        for(int i=1;i<n-1;i++){
        
        int fir=abs(nums[i-1]-nums[i]);
        int sec=abs(nums[i+1]-nums[i]);

        if(fir<=sec) pre[i]=i-1;
        else pre[i]=i+1;
        }

        // for(auto &it : pre) cout<<it<<" ";
        // cout<<endl;

        vector<int>presum(n,0);
        presum[0]=0;
        for(int i=1;i<n;i++){
           if(pre[i-1]==i) presum[i]=presum[i-1]+1;
           else presum[i]=presum[i-1]+abs(nums[i]-nums[i-1]);
        //    cout<<presum[i]<<endl;
        }

        vector<int>suffsum(n,0);
        suffsum[n-1]=0;
        for(int i=n-2;i>=0;i--){
           if(pre[i+1]==i) suffsum[i]=suffsum[i+1]+1;
           else suffsum[i]=suffsum[i+1]+abs(nums[i]-nums[i+1]);
        }
        
        // for(auto &it : presum) cout<<it<<" ";
        // cout<<endl;

        // for(auto &it : suffsum) cout<<it<<" ";
        // return ans;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            // cout<<x<<" "<<y<<endl;

            if(x<y){
                ans[i]=presum[y]-presum[x];
            }
            else ans[i]=suffsum[y]-suffsum[x];
        }

        return ans;
    }
};