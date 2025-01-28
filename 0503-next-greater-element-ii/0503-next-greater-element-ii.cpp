class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n=nums.size();
       int i=2;
       vector<int>num;
       while(i>0){
        for(int j=0;j<n;j++){
            num.push_back(nums[j]);
        }
        i--;
       }
       stack<int>st;
       int m=num.size();
       vector<int>ans(m,-1);
       st.push(num[m-1]);  
       for(int i=m-2;i>=0;i--){
         while(st.size()>0 && st.top()<=num[i]) st.pop();
         if(st.size()!=0) ans[i]=st.top();
         st.push(num[i]);
       }
       vector<int>v;
       for(int i=0;i<m/2;i++){
        v.push_back(ans[i]);
       }
       return v;
    }
};