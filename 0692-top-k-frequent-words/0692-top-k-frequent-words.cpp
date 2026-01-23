class Solution {
public:
    typedef pair<int,string> p;
    //main thing is this
   struct Compare {
    bool operator()(const pair<int, string>& a,
                    const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second < b.second; 
    
        }
        return a.first > b.first; 
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();

        priority_queue<p,vector<p>,Compare>pq;

        unordered_map<string,int>mp;
        for(auto &it : words){
            mp[it]++;
        }

        for(auto &it : mp){
            pq.push({it.second,it.first});
            while(!pq.empty() && pq.size()>k){
                pq.pop();
            }
        }

        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};