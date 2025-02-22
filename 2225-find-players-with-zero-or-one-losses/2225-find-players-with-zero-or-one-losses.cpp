class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> jitna;
        unordered_map<int, int> harna;
        for(int i=0;i<matches.size();i++){
             jitna[matches[i][0]]++;
             harna[matches[i][1]]++;
        }
        vector<int>first;
        vector<int>second;
        for(auto p : jitna){
            if(harna.find(p.first)==harna.end()){
                first.push_back(p.first);
            }
        }
          for(auto p : harna){
            if(p.second==1){
                second.push_back(p.first);
            }
        }
        vector<vector<int>>ans;
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};