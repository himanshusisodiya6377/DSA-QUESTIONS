class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(auto it : s){
            mp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            pair<int,char>p=pq.top();
            pq.pop();
            while(p.first>0){
                ans.push_back(p.second);
                p.first--;
            }
        }
        return ans;
    }
};