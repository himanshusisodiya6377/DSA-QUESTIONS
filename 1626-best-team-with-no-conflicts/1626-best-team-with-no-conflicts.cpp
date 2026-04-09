class Solution {
public:
    // long long ans=0;
    vector<vector<int>>dp;
    int solve(vector<int>&ch,int last,int idx){
        if(idx>=ch.size()){
            return 0;
        }
        
        if(dp[last+1][idx]!=-1) return dp[last+1][idx];

        //can include
        long long inc=0;
        if(last==-1 || ch[last]<=ch[idx]) inc=ch[idx]+solve(ch,idx,idx+1);

        long long not_inc=solve(ch,last,idx+1);

        return dp[last+1][idx]=max(inc,not_inc);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>v;
        for(int i=0;i<ages.size();i++) v.push_back({ages[i],scores[i]});

        sort(v.begin(),v.end());

        vector<int>ch;
        for(auto &it : v) ch.push_back(it.second);

        // dp.resize(ch[ch.size()-1]+1,vector<int>(ch.size(),-1));
        dp.resize(ch.size()+1,vector<int>(ch.size()+1,-1));

        return solve(ch,-1,0);
    }
};