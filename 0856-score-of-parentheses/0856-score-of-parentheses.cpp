class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;

        for(char ch : s) {

            if(ch == '(') {
                st.push(-1);      // marker for '('
            }
            else {

                int val = 0;

                while(st.top() != -1) {
                    val += st.top();
                    st.pop();
                }

                st.pop(); // remove '(' marker

                if(val == 0)
                    st.push(1);       // ()
                else
                    st.push(2 * val); // (A)
            }
        }

        int ans = 0;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};