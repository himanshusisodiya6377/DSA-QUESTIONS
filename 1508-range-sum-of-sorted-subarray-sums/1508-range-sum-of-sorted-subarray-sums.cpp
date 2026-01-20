class Solution {
public:
    int mod=1e9+7;
    typedef pair<int,int> p;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        long long ans=0;

        priority_queue<p,vector<p>,greater<p>>pq;

        for(int i=0;i<n;i++) pq.push({nums[i],i});
        int pos=1;

        while(!pq.empty()){

            auto p=pq.top();
            pq.pop();

            int val=p.first;
            int idx=p.second;
            cout<<val<<endl;

            if(pos>=left && pos<=right) ans+=val;
            else if(pos>right) break;
            
            if(idx<n-1) pq.push({val+nums[idx+1],idx+1});

            pos++;

        }

        return ans%mod;

    }
};