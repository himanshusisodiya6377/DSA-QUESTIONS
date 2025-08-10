class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long long m = 1;
        long long count = 30;
        unordered_set<string> st;
        while (count > 0) {
            string ans = "";
            long long temp = m;
            while (temp > 0) {
                long long k = temp % 10;
                ans.push_back(char(k + '0'));
                temp /= 10;
            }
            sort(ans.begin(), ans.end());
            st.insert(ans);
            count--;
            m*=2;
        }

        string check="";
        while(n>0){
            long long k=n%10;
            check.push_back(char(k+'0'));
            n/=10;
        }
        sort(check.begin(),check.end());
        return st.find(check)!=st.end();
    }
};