//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n=arr.size();
        int loweridx=-1;
        int upparidx=-1;
        //lower bound
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==target){
                loweridx=mid;
                hi=mid-1;
            }
            else if(arr[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        lo=0,hi=n-1;
        //uppar bound
         while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==target){
                upparidx=mid;
                lo=mid+1;
            }
             else if(arr[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
         if(loweridx==-1 && upparidx==-1) return 0;
        int count=abs(loweridx-upparidx)+1;
       
        return count;
        
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends