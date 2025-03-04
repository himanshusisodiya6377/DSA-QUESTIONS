class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        // stack approach question
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (st.size() == 0)
                st.push(s[i]);
            else {
                int ch = st.top();
                int x = s[i];
                if (ch+32==x || ch-32==x) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
         string ans = "";
            while (st.size() > 0) {
                char ch = st.top();
                ans.push_back(ch);
                st.pop();
            }
          reverse(ans.begin(), ans.end());
            return ans;
    }
};