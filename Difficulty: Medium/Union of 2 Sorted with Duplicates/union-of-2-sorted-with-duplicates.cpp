//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n=a.size();
        int m=b.size();
        vector<int>c;
        int i=0,j=0;
        while(i<n && j<m){
           if (i > 0 && a[i] == a[i - 1]) {  // Skip duplicates in a
                i++;
                continue;
            }
            if (j > 0 && b[j] == b[j - 1]) { 
                j++;
                continue;
            }

            if (a[i] < b[j]) {
                c.push_back(a[i++]);
            } else if (a[i] > b[j]) {
                c.push_back(b[j++]);
            } else { // a[i] == b[j]
                c.push_back(a[i]);
                i++;
                j++;
            }
        }
        while(i==n && j<m){
             if(b[j-1]==b[j]) j++;
                   else {
                       c.push_back(b[j]);
                       j++;
                   }
        }
        while(j==m && i<n){
             if(a[i-1]==a[i]) i++;
                   else {
                       c.push_back(a[i]);
                       i++;
                   }
        }
    return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends