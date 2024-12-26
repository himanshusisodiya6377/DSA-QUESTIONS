//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int>v;
        vector<int>ind(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            ind[arr[i]-1]++;
        }
        int miss;
        int rep;
        for(int i=0;i<ind.size();i++){
            if(ind[i]==0) miss=i+1;
            if(ind[i]==2) rep=i+1;
        }
        v.push_back(rep);
        v.push_back(miss);
        return v;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends