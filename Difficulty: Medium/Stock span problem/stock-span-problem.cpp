class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n,0);
        
        stack<pair<int,int>>st;  //value with current ans
        
        for(int i=0;i<n;i++){
            int cnt=1;
            
            while(!st.empty() && st.top().first<=arr[i]){
                cnt+=st.top().second;
                st.pop();
            }
            
            ans[i]=cnt;
            st.push({arr[i],cnt});
        }
        
        return ans;
    }
};