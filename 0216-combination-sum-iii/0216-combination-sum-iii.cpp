class Solution {
public:

//    unordered_set<int>visit;

   void solve(vector<vector<int>>&ans,vector<int>&temp,int k,int n,int sum,int idx){
    if(temp.size()>k || sum>n) return ;
    if(temp.size()==k && sum==n){
        ans.push_back(temp);
        return;
    }

    for(int i=idx;i<=9;i++){
 
      
         temp.push_back(i);
         sum+=i;
        //  visit.insert(i);
         solve(ans,temp,k,n,sum,i+1);
         temp.pop_back();
         sum-=i;
        //  visit.erase(i);
       

    }
   }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,k,n,0,1);
        return ans;
    }
};