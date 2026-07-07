class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        vector<int>pre(n,0);
        pre[0]=1;

        for(int i=1;i<n;i++){
            if(nums[i]%2==0 && nums[i-1]%2!=0  ||  nums[i]%2!=0 && nums[i-1]%2==0  ) pre[i]=pre[i-1]+1;
            else pre[i]=1;
        }

        // for(auto &it : pre) cout<<it<<" ";
        // for(int i=1;i<n;i++) pre[i]+=pre[i-1];
// 

        vector<bool>ans(queries.size(),false);

        for(int i=0;i<queries.size();i++){
            int fir=queries[i][0];
            int sec=queries[i][1];

            int len=sec-fir+1;
            int pre_len=pre[sec]-pre[fir]+1;

            if(len==pre_len) ans[i]=true;
        }

        return ans;
    }
};