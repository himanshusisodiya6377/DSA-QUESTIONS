//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool checkKthBit(int n, int k) {
       int temp=1<<(k);
       if((n&temp)==0) return false;
       else return true;
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {
    int t;
    cin >> t; // taking testcases
    while (t--) {
        long long n;
        cin >> n; // input n
        int k;
        cin >> k; // bit number k
        Solution obj;
        if (obj.checkKthBit(n, k))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends