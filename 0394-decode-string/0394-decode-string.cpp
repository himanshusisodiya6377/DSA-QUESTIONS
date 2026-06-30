class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> nume;

        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                nume.push(num);
                num = 0;
                st.push("[");
            }
            else if (c == ']') {
                string curr = "";

                while (!st.empty() && st.top() != "[") {
                    curr = st.top() + curr;
                    st.pop();
                }

                st.pop(); // remove '['

                int k = nume.top();
                nume.pop();

                string temp = "";
                while (k--) temp += curr;

                st.push(temp);
            }
            else { // character
                st.push(string(1, c));
            }
        }

        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};