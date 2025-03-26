class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        int wind=ceil(n/4.0);
        if(n==wind*4) wind++;
        int i=0,j=wind-1;
        while(j<n){
            if(arr[i]==arr[j]) return arr[i];
            else{
                i++;
                j++;
            }
        }
        return 0;
    }
};