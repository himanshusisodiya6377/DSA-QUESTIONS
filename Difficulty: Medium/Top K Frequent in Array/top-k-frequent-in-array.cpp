class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto it : arr){
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
