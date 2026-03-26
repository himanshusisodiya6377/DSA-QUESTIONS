class Solution {
public:
    int cnt;
    // string ans;
    unordered_map<string,int>mp;
    bool check(string &s,string &ans){
      vector<char>visit(26,0);

      for(auto &it : s){
        if(visit[it-'a']>0) return false;
        visit[it-'a']++;
      }

      for(auto &it : ans){
         if(visit[it-'a']>0) return false;
      }

      return true;
    }
    int solve(vector<string>&arr,int idx,string ans){
        if(idx>=arr.size()){
           return ans.length();
        }
        
        if(mp.find(ans)!=mp.end()) return mp[ans];
        
        int include=0;
        int exclude=0;

        if(check(arr[idx],ans)){
            include=solve(arr,idx+1,ans+arr[idx]);
            exclude=solve(arr,idx+1,ans);
        }
        else{
            exclude=solve(arr,idx+1,ans);
        }

        return mp[ans]=max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        // cnt=0;
        mp.clear();
        string ans="";
        return solve(arr,0,ans);
    }
};