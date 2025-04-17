//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
        int countsubset(vector<int>& nums, int target) {
        int n=nums.size();
        //intialisation
         vector<vector<int>>t(n+1,vector<int>(target+1,0));
        for (int i = 0; i <= n; i++) t[i][0] = 1;
         
        for(int i=1;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j] + t[i-1][j-nums[i-1]];
                }
                else t[i][j]=t[i-1][j];
                
            }
        }
      return t[n][target];
    }
    int countPartitions(vector<int>& arr, int d) {
      int n=arr.size();
     int sum=0;
     for(auto v : arr) sum+=v;
     //initialization
     if (sum < d || (sum + d) % 2 != 0) return 0;
     int target=(sum+d)/2;
     return countsubset(arr,target);
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
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends