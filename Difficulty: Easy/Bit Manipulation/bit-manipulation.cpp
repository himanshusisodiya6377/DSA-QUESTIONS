//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void bitManipulation(int num, int i) {
        int ibit;
        int temp=1<<(i-1);
        if((num&temp)==0) ibit=0;
        else ibit=1;
        num=num|temp;
        int x=(num&(~temp));
        cout<<ibit<<" "<<num<<" "<<x;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends