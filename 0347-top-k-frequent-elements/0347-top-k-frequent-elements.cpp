class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>>pq;
        int i=0,j=0;
        while(j<n){
            while(j<n && nums[i]==nums[j]) j++;
                int len=j-i;
        cout<<"1"<<endl;
                pq.push({len,nums[i]});
                i=j;
                j++;
        }
        if(i<n) pq.push({j-i,nums[i]});
        vector<int>ans;
       
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        cout<<"1"<<endl;
        return ans;
    }
};