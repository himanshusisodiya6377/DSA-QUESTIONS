class Solution {
public:
    int calPoints(vector<string>& arr) {
        int n=arr.size();
        stack<int>st;
        for(int i=0;i<n;i++){
             if(arr[i]=="C") st.pop();
            else if(arr[i]=="D") st.push(2*st.top());
            else if(arr[i]=="+"){
                int x=st.top();
                st.pop();
                int y=x;
                x+=st.top();
                st.push(y);
                st.push(x);
            }
            else{
                st.push(stoi(arr[i]));
            }
        }
        int sum=0;
        while(st.size()>0){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};