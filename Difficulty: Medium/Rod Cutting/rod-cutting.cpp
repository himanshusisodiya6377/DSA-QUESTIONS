//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
       int n=price.size();
       vector<int>length;
       for(int i=1;i<=n;i++) length.push_back(i);
       vector<vector<int>>t(n+1,vector<int>(n+1,0));
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               if(length[i-1]<=j)
               t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
               else t[i][j]=t[i-1][j];
           }
       }
       return t[n][n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends