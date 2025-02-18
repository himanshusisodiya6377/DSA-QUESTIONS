class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>ms;
        unordered_map<int,int>mf;
        int k=trust.size();
        if(k==0) return n;
        for(int i=0;i<k;i++){
            ms[trust[i][1]]++;
            mf[trust[i][0]]++;
        }
        vector<int>v;
        for(auto p: ms){
            if(p.second==n-1) v.push_back(p.first);
        }
        for(int i=0;i<v.size();i++){
            if(mf.find(v[i])==mf.end()){
               return v[i];
            }
        }
       return -1;
    }
};