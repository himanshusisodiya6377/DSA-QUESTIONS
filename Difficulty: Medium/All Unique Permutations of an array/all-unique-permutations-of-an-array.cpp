class Solution {
  public:
  
    void solve(vector<int>&arr,int idx,set<vector<int>>&st){
        if(idx>=arr.size()){
            return;
        }
        st.insert(arr);
        for(int i=idx;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                swap(arr[i],arr[j]);
                solve(arr,i+1,st);
                swap(arr[i],arr[j]);
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        int n=arr.size();
        // int i=0,j=1;
        set<vector<int>>st;
        st.insert(arr);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(arr[i],arr[j]);
                solve(arr,i+1,st);
                swap(arr[i],arr[j]);
            }
        }
        for(auto it : st){
            ans.push_back(it);
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};