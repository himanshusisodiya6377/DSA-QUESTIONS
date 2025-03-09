class Solution {
public:
    string smallestNumber(string pattern) {
        int k = pattern.length();
        string ans = "";
        // stack<char> st;
        stack<char> temp;
       ans+=to_string(1);
        int count = 2;
        int n = 0;
        for (int i = 0; i < k; i++) {
            if (pattern[i] == 'I') {
                while (temp.size() != 0) {
                    int m = temp.top();
                    temp.pop();
                   ans+=to_string(m);
                }
                if (n != 0) {
                    // st.push(n);
                    ans+=to_string(n);
                    n = 0;
                }
               ans+=to_string(count);
                count++;
            } else {
                if (n == 0) {
                    n = ans.back()-48;
                    ans.pop_back();
                }
                temp.push(count);
                count++;
            }
        }
        while (temp.size() != 0) {
            int m = temp.top();
            temp.pop();
            // st.push(m);
            ans+=to_string(m);
        }
        if (n != 0) {
           ans+=to_string(n);
            n = 0;
        }
        // while (st.size() != 0) {
        //     int n = st.top();
        //     ans += to_string(n);
        //     st.pop();
        // }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};