class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,int>mp;
        long long ans=0;

        for(auto &it : rectangles){
            mp[(1.0*it[0])/it[1]]++;
        }

        for(auto &it : rectangles){
            double req=(1.0*it[0])/it[1];
            ans+=(mp[req]-1);
            mp[req]--;
        }

        return ans;
    }
};