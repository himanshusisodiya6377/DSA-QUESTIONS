class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> st;
        vector<int> ans(n, 0);
        // st.insert(A[0]);
        for (int i = 0; i < n; i++) {
            st.insert(A[i]);
            int count = 0;
            for (int j = 0; j <= i; j++) {
                if (st.find(B[j]) != st.end())
                    count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};