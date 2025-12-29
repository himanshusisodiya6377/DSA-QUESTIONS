class Solution {
public:
    bool solve(queue<char>& q, char ch) {
        bool flag;
        if (ch == '&') {
            flag = true;
            while (!q.empty()) {
                flag = flag && (q.front() == 'f' ? false : true);
                q.pop();
            }
        } else if (ch == '|') {
            flag = false;
            while (!q.empty()) {
                flag = flag || (q.front() == 'f' ? false : true);
                q.pop();
            }
        }
        return flag;
    }
    bool sol(char fir) {
        if (fir == 'f')
            return true;
        return false;
    }
    bool parseBoolExpr(string exp) {
        int n = exp.length();

        stack<char> st;
        stack<char> op;

        for (int i = 0; i < n; i++) {
            if (exp[i] == 'f')
                st.push(exp[i]);
            else if (exp[i] == 't')
                st.push(exp[i]);
            else if (exp[i] == '&' || exp[i] == '|' || exp[i] == '!')
                op.push(exp[i]);
            else if (exp[i] == '(')
                st.push(exp[i]);
            else if (exp[i] == ')') {
                char ch = op.top();
                // cout<<ch<<endl;
                op.pop();

                if (ch == '!') {
                    // op.pop();
                    char fir = st.top();
                    st.pop();
                    st.pop(); // for '('
                    bool res = sol(fir);
                    // cout<<res<<endl;
                    st.push((res == false ? 'f' : 't'));
                }
                else{
                queue<char> q;
                while (st.size() > 0 && st.top() != '(') {

                    char fir = st.top();
                    st.pop();
                    q.push(fir);
                }

                st.pop();

                bool res = solve(q, ch);

                // cout<<res<<endl;

                (res == false ? st.push('f') : st.push('t'));
                }
            }
        }

        // cout<<st.top();
        // cout<<op.size()<<endl;
        while (!op.empty()) {
            op.pop();
            char fir = st.top();
            st.pop();
            bool res = sol(fir);
            // cout<<res<<endl;
            st.push((res == false ? 'f' : 't'));
        }

        return (st.top() == 'f' ? false : true);
    }
};