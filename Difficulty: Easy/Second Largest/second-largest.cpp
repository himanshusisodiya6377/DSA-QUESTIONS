//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n=arr.size();
        int max,smax;
        if(arr[0]>arr[1]){
            max=arr[0];
            smax=arr[1];
        }
        else{
            max=arr[1];
            smax=arr[0];
        }
        if(max==smax) return -1;
        for(int i=2;i<n;i++){
            if(max<arr[i]){
                smax=max;
                max=arr[i];
            }
            else if (smax<arr[i] && arr[i]!=max) smax=arr[i];
        }
        return smax;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends