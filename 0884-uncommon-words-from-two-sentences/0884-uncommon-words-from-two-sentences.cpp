class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
     stringstream ss1(s1);
     stringstream ss2(s2);
     string word1="";
     string word2="";
     unordered_map<string,int>mp;
     vector<string>ans;
     while(ss1>>word1){
        mp[word1]++;
     }
     while(ss2>>word2){
        mp[word2]++;
     }
    for(auto p:mp){
        if(p.second==1) ans.push_back(p.first);
    }
     return ans;
    }
};