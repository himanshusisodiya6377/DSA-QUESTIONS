class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        long long r=wall.size();
        unordered_map<int,int>mp;
        long long sm=0;
        for(auto &it : wall[0]) sm+=it;

        for(auto &it : wall){
            long long sum=0;
            for(auto &x : it){
                sum+=x;
                mp[sum]++;
            }
        }

        // for(auto &it : mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        long long mini=INT_MAX;
        for(auto &it : mp){
            if(it.first!=0 && it.first!=sm) mini=min(mini,r-it.second);
        }

        return (mini==INT_MAX ? r : mini);
    }
};