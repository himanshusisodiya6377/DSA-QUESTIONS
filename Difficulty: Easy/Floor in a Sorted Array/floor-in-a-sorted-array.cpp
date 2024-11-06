//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
       int n=arr.size();
       int lo=0,hi=n-1,mid;
       while(lo<=hi){
            mid=(lo+hi)/2;
           if(arr[mid]==k) return mid;
           else if(arr[mid]>k) hi=mid-1;
           else lo=mid+1;
       } 
       if(arr[mid]<k) return mid;
       else return mid-1;
       
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, k);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends