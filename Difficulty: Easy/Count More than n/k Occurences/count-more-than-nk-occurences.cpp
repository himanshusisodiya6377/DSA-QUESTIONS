//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
       sort(arr,arr+n);
       int idx=0;
      // int max=0;
       int count=0;
       for(int i=0;i<n;i++){
           if(arr[i]!=arr[i+1]){
               int diff=i+1-idx;
               idx=i+1;
               if(diff>(n/k)) count++;
               //if(diff>max) max=diff;
           }
           
       }
       return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends