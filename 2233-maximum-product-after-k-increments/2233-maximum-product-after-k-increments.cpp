class Solution {
public:
    int mod=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();

        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto &it : nums) pq.push(it);

        while(k>0){
            auto p=pq.top();
            pq.pop();

            p++;
            pq.push(p);
            k--;
        }

        int ans=1;
        while(!pq.empty()){
            ans=(1LL*ans*pq.top())%mod;
            pq.pop();
            ans=ans%mod;
        }

        return ans;
    }
};