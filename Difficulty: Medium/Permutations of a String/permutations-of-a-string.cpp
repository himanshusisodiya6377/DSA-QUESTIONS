class Solution {
  public:
  
   vector<string>ans;
  
    void solve(string &s,string &temp,vector<bool>&vis){
        
        if(temp.length()==s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<s.length();i++){
            
            if(vis[i]==true) continue;
            
            if(i>0 && s[i]==s[i-1] && !vis[i-1]) continue;
            
            vis[i]=true;
            temp.push_back(s[i]);
            solve(s,temp,vis);
            vis[i]=false;
            temp.pop_back();
            
        }
        
    }
  
    vector<string> findPermutation(string &s) {
         sort(s.begin(),s.end());
         int n=s.length();
         string temp="";
         vector<bool>vis(n,false);
         solve(s,temp,vis);
         
         return ans;
         
    }
};
