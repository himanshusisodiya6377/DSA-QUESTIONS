class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //done all three
        //optimization with hashmap 
        int n=nums2.size();
        vector<int>nextgre(n,-1);
        stack<int>st;
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){//nextsmaller
            while(st.size()>0 && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.size()!=0){
                nextgre[i]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]) ans.push_back(nextgre[j]);
            }
        }
        return ans;
    }
};