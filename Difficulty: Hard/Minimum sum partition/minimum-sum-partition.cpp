//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int minDifference(vector<int>& arr) {
     int n=arr.size();
     int sum=0;
     for(auto v : arr) sum+=v;
     //initialization
     vector<vector<bool>>t(n+1,vector<bool>(sum+1,false));
     for(int i=0;i<n+1;i++) t[i][0]=true;
     
     for(int i=1;i<n+1;i++){
         for(int j=1;j<sum+1;j++){
             if(arr[i-1]<=j)
             t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];
             else t[i][j]=t[i-1][j];
         }
     }
     //getting all possible value that can be achieve
        vector<int>v(sum+1,false);
        for(int i=0;i<sum+1;i++){
            if(t[n][i]==true) v[i]=true;
        }
        int mini=INT_MAX;
        for(int i=sum/2;i>=0;i++){
            if(v[i]==true){
            mini=i;
            break;
            }
        }
        return abs(sum-2*mini);
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

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends