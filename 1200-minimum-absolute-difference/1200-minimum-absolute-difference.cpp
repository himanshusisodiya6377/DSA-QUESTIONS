class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        int diff=INT_MAX;
        
        unordered_set<int>st;
        
        for(int i=0;i<n-1;i++) {
            diff=min(diff,arr[i+1]-arr[i]);
            st.insert(arr[i]);
        }

        st.insert(arr[n-1]);

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            if(st.count(arr[i]+diff)) ans.push_back({arr[i],arr[i]+diff});
        }

        return ans;
    }
};