class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        stack<int>gt;
        stack<int>st;
        for(int i=0;i<g.size();i++) gt.push(g[i]);
        for(int i=0;i<s.size();i++) st.push(s[i]);
        while(st.size()>0 && gt.size()>0){
            if(st.top()==gt.top()){
                count++;
                gt.pop();
                st.pop();
            }
            else if(gt.top()<st.top()) {
                st.pop();
                count++;
                gt.pop();
            }
            else gt.pop();
        }
        return count;

        // int i=0,j=0,count=0;
        // sort(g.begin(),g.end());
        // sort(s.begin(),s.end());
        // int n=g.size();
        // int m=s.size();
        // while(i<n && j<m){
        // if(s[j]>=g[i]){
        //     count++;
        //     i++;
        //     j++;
        // }
        // else j++;
        // }
        // return count;

        
    }
};