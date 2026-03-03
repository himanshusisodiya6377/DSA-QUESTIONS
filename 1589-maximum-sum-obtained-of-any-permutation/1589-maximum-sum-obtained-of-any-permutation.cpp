class Solution {
public:
    int mod=1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        
        int n=nums.size();
        int r=requests.size();

        vector<int>freq(n,0);
        for(auto &it : requests){
            int st=it[0],end=it[1];
            freq[st]++;
            (end < n-1 ? freq[end+1]-- : 0);
        }

        // for(auto &it : freq) cout<<it<<" ";
        priority_queue<int>pq;
        pq.push(freq[0]);

        for(int i=1;i<n;i++){
            freq[i]+=freq[i-1];
            if(freq[i]>0) pq.push(freq[i]);
        }

        sort(nums.begin(),nums.end());
        long long sum=0;

        for(int i=n-1;i>=0 && !pq.empty();i--){
            sum+=1LL*nums[i]*pq.top();
            sum=sum%mod;
            pq.pop();
        }

        return sum%mod;
    }
};