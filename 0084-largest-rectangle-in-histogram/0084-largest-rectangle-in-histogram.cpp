class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>presmal(n,-1);
        stack<int>st;
        st.push(heights[0]);
        stack<int>idx;
        idx.push(0);
        for(int i=1;i<n;i++){//presmaller
            while(st.size()>0 && st.top()>=heights[i]){
                st.pop();
                idx.pop();
            }
            if(st.size()!=0){
                presmal[i]=idx.top();
            }
            st.push(heights[i]);
            idx.push(i);
        }
        vector<int>nextsmal(n,n);
        stack<int>sc;
        sc.push(heights[n-1]);
        stack<int>idsc;
        idsc.push(n-1);
        for(int i=n-2;i>=0;i--){//nextsmaller
            while(sc.size()>0 && sc.top()>=heights[i]){
                sc.pop();
                idsc.pop();
            }
            if(sc.size()!=0){
                nextsmal[i]=idsc.top();
            }
            sc.push(heights[i]);
            idsc.push(i);
        }
        int area=INT_MIN;
        int sum;
        for(int i=0;i<n;i++){
            sum=heights[i]*(nextsmal[i]-presmal[i]-1);
            if(sum>area) area=sum;
        }
        return area;
    }
};