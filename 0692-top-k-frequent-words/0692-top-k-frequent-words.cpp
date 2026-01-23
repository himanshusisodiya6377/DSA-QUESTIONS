class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;//freq map
        }
        vector<string>ans;
        vector<pair<string, int>>Pairs;
        for(auto p : mp){
            Pairs.push_back(p);
        }
        sort(Pairs.begin(), Pairs.end(), [](const auto& a, const auto& b) {
        return a.second < b.second; // Ascending order
    }); 
    int m=Pairs.size()-1;
       for(int i=m;i>m-k;i--){
          ans.push_back(Pairs[i].first);
       }
    //    sort(ans.begin(),ans.end());
       return ans;
    }
};