class Solution {
public:
    typedef long long ll;
    ll check(ll n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
   }
    long long sumOfLargestPrimes(string s) {
        int n=s.length();
        set<ll>st;
        priority_queue<ll>pq;
        ll temp=n;
        ll ans=0;
        ll count=3;
      
        while (temp > 0) {
            ll i = n - temp, j = n - 1;
            while (i >= 0) {
                ll len = j - i + 1;
                string subs = s.substr(i, len);
                    ll get = stoll(subs);
                    if (check(get) && st.find(get) == st.end()) {
                        pq.push(get);
                        st.insert(get);
                    }
                i--;
                j--;
            
            
        }
        temp--;
        }
      while (!pq.empty() && count--) {
            ans += pq.top();
            pq.pop();
        }
      return ans;
    }
};
// #include <iostream>
// #include <string>
// #include <cmath>
// #include <set>
// #include <queue>
// using namespace std;

// class Solution {
// public:
//     bool check(long long n) {
//         if (n <= 1) return false;
//         for (long long i = 2; i * i <= n; ++i) {
//             if (n % i == 0) return false;
//         }
//         return true;
//     }

//     long long sumOfLargestPrimes(string s) {
//         int n = s.length();
//         set<long long> st;
//         priority_queue<long long> pq;
//         int temp = n;

//         while (temp > 0) {
//             int i = n - temp, j = n - 1;
//             while (i >= 0) {
//                 int len = j - i + 1;
//                 string subs = s.substr(i, len);
//                 try {
//                     long long num = stoll(subs);
//                     if (check(num) && st.find(num) == st.end()) {
//                         st.insert(num);
//                         pq.push(num);
//                     }
//                 } catch (const invalid_argument& e) {
//                     // Skip invalid substrings
//                 } catch (const out_of_range& e) {
//                     // Skip out-of-range substrings
//                 }
//                 i--;
//                 j--;
//             }
//             temp--;
//         }

//         long long ans = 0;
//         int count = 3;
//         while (!pq.empty() && count--) {
//             ans += pq.top();
//             pq.pop();
//         }

//         return ans;
//     }
// };
