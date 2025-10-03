class Solution {
  public:
  
    vector<string>g={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  
    void solve(vector<int>&arr,int idx,string ans,vector<string>&ass){
        if(idx>=arr.size()){
            ass.push_back(ans);
            return;
        }
        
        string copy=g[arr[idx]];
        
        if(copy==""){
             solve(arr,idx+1,ans,ass);
             return;
        }
        
        for(int i=0;i<copy.length();i++){
            ans.push_back(copy[i]);
            solve(arr,idx+1,ans,ass);
            ans.pop_back();
        }
    }
  
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        int n=arr.size();
        string ans="";
        vector<string>ass;
        
        string copy=g[arr[0]];
        
         if(copy==""){
             solve(arr,1,ans,ass);
             return ass;
        }
        
        for(int i=0;i<copy.length();i++){
            ans.push_back(copy[i]);
            solve(arr,1,ans,ass);
            ans.pop_back();
        }
        
        return ass;
    }
};