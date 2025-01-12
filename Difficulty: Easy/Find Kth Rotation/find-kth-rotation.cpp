//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
         int n=nums.size();
        int lo=0,hi=n-1;
        int mini=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]<nums[mini]) mini=mid;
            if(nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid-1;
        }
        return mini;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends