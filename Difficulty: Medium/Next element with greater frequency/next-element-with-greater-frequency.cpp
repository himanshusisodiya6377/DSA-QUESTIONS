class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp; //element with freq
        priority_queue<pair<int,int>>pq; //freq with element 
        int n=arr.size();
        
        vector<int>ans(n,-1);
        
        for(auto &it : arr) mp[it]++;
        
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
         
         while(!st.empty() && st.top().first<=mp[arr[i]]) st.pop();
         
         if(!st.empty()) ans[i]=st.top().second;
         
         st.push({mp[arr[i]],arr[i]});
            
        }
        
        return ans;
    }
};
