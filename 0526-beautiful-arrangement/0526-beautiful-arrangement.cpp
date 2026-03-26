class Solution {
public:
    // int cnt=0;
    map<vector<int>,int>mp;
    bool check(vector<int>&v){
        for(int i=1;i<v.size();i++){
           if(v[i]%i!=0 && i%v[i]!=0) return false;
        }
        return true;
    }
    int solve(int n,vector<int>v){
        if(n==0){
            if(check(v)) return 1;
            return 0;
        }

        if(mp.find(v)!=mp.end()) return mp[v];
        
        int ans=0;
        for(int i=1;i<v.size();i++){
               if(v[i]!=0 || (i%n!=0 && n%i!=0)) continue;
               v[i]=n;
               ans+=solve(n-1,v);
               v[i]=0;
        }

        return mp[v]=ans;
    }
    int countArrangement(int n) {
        vector<int>v(n+1,0);
        mp.clear();
        return solve(n,v);
    }
};