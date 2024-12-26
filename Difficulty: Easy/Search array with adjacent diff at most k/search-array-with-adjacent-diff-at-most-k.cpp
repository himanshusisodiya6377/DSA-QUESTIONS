//{ Driver Code Starts
// C++ program to search an element in an array
// where difference between all elements is 1
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        // code here
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x) return i;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int k, x;
        cin >> k >> x;
        Solution sol;
        int ans = sol.findStepKeyIndex(arr, k, x);
        cout << ans << endl;
        cout << '~' << endl;
    }
    return 0;
}

// } Driver Code Ends