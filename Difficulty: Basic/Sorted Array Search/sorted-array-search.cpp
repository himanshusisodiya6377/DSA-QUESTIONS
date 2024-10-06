//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N, int K) {
  int lo=0,hi=N-1;
  while(lo<=hi){
      int mid =lo+(hi-lo)/2;
      if(arr[mid]<K) lo=mid+1;
     else  if(arr[mid]>K) hi=mid-1;
      else if(arr[mid]==K) return 1;
  }
  return -1;
        // Your code here
    }
};

//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;
    }

    return 0;
}

// } Driver Code Ends