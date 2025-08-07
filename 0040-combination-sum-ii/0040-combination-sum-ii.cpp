class Solution {
public:

    // set<vector<int>>st;
  
   void solve(vector<int>& candidates, vector<vector<int>>&ans,vector<int>&temp,int tar,int sum,int idx,vector<bool>&vis){

      if(sum>tar) return;

      if(sum==tar){
        ans.push_back(temp);
        return;
      }

      for(int i=idx;i<candidates.size();i++){
 
         if(vis[i]==true) continue;

         if(i>0 && candidates[i]==candidates[i-1] && !vis[i-1]) continue;

          temp.push_back(candidates[i]);
          sum+=candidates[i];
          vis[i]=true;

          solve(candidates,ans,temp,tar,sum,i+1,vis);
           
          vis[i]=false;
          temp.pop_back();
          sum-=candidates[i];

      }

   }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>vis(candidates.size(),false);
        solve(candidates,ans,temp,target,0,0,vis);
        return ans;
    }
};