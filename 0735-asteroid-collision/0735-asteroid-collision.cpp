class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n=ast.size();

        stack<int>st;

        for(int i=0;i<n;i++){
            if(st.empty()) st.push(ast[i]);
            else if(ast[i]>0) st.push(ast[i]);
            else{
                //we have negartive
                // if top is also negative 
                if(!st.empty() && st.top()<0) st.push(ast[i]);
                else{
                    while(!st.empty() && st.top()>0 && st.top()<abs(ast[i])) st.pop();
                    if(st.empty() || st.top()<0) st.push(ast[i]);
                    if(!st.empty() && st.top()>0 && st.top()==abs(ast[i])) st.pop();
                }
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};