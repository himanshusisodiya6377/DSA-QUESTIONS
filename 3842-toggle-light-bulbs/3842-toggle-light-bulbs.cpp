class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int>st;
        for(auto &it : bulbs){
            if(st.find(it)!=st.end()) st.erase(it);
            else st.insert(it);
        }
        vector<int>ans;
        for(auto &it : st)ans.push_back(it);
        return ans;
    }
};