//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
//   int t[1001][1001];
  int mod = (int)(1e9 + 7);
    int perfectSum(vector<int>& nums, int target) {
        int n=nums.size();
        //intialisation
         vector<vector<int>>t(n+1,vector<int>(target+1,0));
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<target+1;j++){
        //         if(i==0) t[i][j]=0;
        //         if(j==0) t[i][j]=1;
        //     }
        // }
        for (int i = 0; i <= n; i++) t[i][0] = 1;
         
        for(int i=1;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j] + t[i-1][j-nums[i-1]];
                }
                else t[i][j]=t[i-1][j];
                
                t[i][j]%=mod;
            }
        }
      return t[n][target]%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends