class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        if(n==1) return heights[0];
        vector<int>v(n,0);
        st.push(heights[n-1]);
        for(int i=n-2;i>=0;--i){
            while(st.size()>0 && st.top()<heights[i]) st.pop();
            if(st.size()!=0) v[i]=heights[i];
            st.push(heights[i]);
        }
        int max=INT_MIN;
          for(int i=0;i<v.size();i++){
             if(max<v[i]) max=v[i];
    }
    return 2*max;
   }
};