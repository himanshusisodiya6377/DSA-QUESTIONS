class Solution {
public:
    int maxarea(vector<int>v){
       int n=v.size();
        vector<int>presmal(n,-1);
        stack<int>st;
        st.push(v[0]);
        stack<int>idx;
        idx.push(0);
        for(int i=1;i<n;i++){//presmaller
            while(st.size()>0 && st.top()>=v[i]){
                st.pop();
                idx.pop();
            }
            if(st.size()!=0){
                presmal[i]=idx.top();
            }
            st.push(v[i]);
            idx.push(i);
        }
        vector<int>nextsmal(n,n);
        stack<int>sc;
        sc.push(v[n-1]);
        stack<int>idsc;
        idsc.push(n-1);
        for(int i=n-2;i>=0;i--){//nextsmaller
            while(sc.size()>0 && sc.top()>=v[i]){
                sc.pop();
                idsc.pop();
            }
            if(sc.size()!=0){
                nextsmal[i]=idsc.top();
            }
            sc.push(v[i]);
            idsc.push(i);
        }
        int area=INT_MIN;
        int sum;
        for(int i=0;i<n;i++){
            sum=v[i]*(nextsmal[i]-presmal[i]-1);
            if(sum>area) area=sum;
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>v(col,0);
        int maxi=INT_MIN;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1'){
                    v[j]++;
                }
                else v[j]=0;
            }
           int area=maxarea(v);
           if(area>maxi) maxi=area;
        }
        return maxi;
    }
};