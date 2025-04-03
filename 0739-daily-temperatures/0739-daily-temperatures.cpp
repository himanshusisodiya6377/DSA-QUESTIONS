class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
     int n=temp.size();
     stack<pair<int,int>>st;
     vector<int>ans(n,0);
     st.push({temp[n-1],1});
     for(int i=n-2;i>=0;i--){
        int span=1;
        while(st.size()>0 && st.top().first<=temp[i]){
            span+=st.top().second;
            st.pop();
        }
        st.push({temp[i],span});
        if(st.size()==1) ans[i]=0;
        else{
            ans[i]=span;
        }
     }
     return ans;
    }
};