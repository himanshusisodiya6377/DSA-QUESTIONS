class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       unordered_map<int,int>pr;
       unordered_set<int>st;
       int n=arr1.size();
       int m=arr2.size();
       vector<int>v;
       for(int i=0;i<n;i++){
        pr[arr1[i]]++;//freq map
       }
        for(int i=0;i<m;i++){
         st.insert(arr2[i]);
       }
       for(int i=0;i<m;i++){
            for(int j=0;j<pr[arr2[i]];j++) v.push_back(arr2[i]);
       }
       sort(arr1.begin(),arr1.end());
       for(int i=0;i<n;i++){
        if(st.find(arr1[i])!=st.end()) continue;
        v.push_back(arr1[i]);
       }
       return v;

    }
};