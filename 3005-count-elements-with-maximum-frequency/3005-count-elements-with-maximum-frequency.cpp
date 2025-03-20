class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int ans=0;
        priority_queue<int>pq;
        for(auto p : mp){
          pq.push(p.second);
        }
        int maxi=pq.top();
        while(pq.size()>0 && pq.top()==maxi){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};