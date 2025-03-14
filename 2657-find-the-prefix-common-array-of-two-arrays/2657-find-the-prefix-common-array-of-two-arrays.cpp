class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        // unordered_set<int> st;
        vector<int> ans(n, 0);
        // // st.insert(A[0]);
        // for (int i = 0; i < n; i++) {
        //     st.insert(A[i]);
        //     int count = 0;
        //     for (int j = 0; j <= i; j++) {
        //         if (st.find(B[j]) != st.end())
        //             count++;
        //     }
        //     ans[i] = count;
        // }
        // return ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int count=0;
            mp[A[i]]++;
            mp[B[i]]++;
            if(mp[A[i]]==2 && A[i]!=B[i]) count++;
            if(mp[B[i]]==2) count++;
           if(i!=0) ans[i]=ans[i-1] + count;
           else ans[i]=count;
        }
        return ans;
    }
};