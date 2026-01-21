class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();

        priority_queue<pair<int,int>>pq; //value with lastest index

        int ans=INT_MIN;

        int i=n-1;

        while(i>=0){

            while(!pq.empty() && pq.top().second-i>k){
                ans=max(ans,pq.top().first);
                pq.pop();
            }

            if(!pq.empty()){
                auto p=pq.top();
                pq.push({p.first+nums[i],i});
            }

            pq.push({nums[i],i});
            i--;
        }

        return max(ans,pq.top().first);
    }
};