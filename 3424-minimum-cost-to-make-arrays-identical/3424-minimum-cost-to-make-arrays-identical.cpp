class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
    long long value1=0;
    long long i=0,j=0;
    while(i<arr.size()){
        value1+=abs(brr[j]-arr[i]);
        i++;
        j++;
    }
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
     long long value2=0;
    i=0,j=0;
    while(i<arr.size()){
        value2+=abs(brr[j]-arr[i]);
        i++;
        j++;
    } 
    value2+=k;
    return min(value1,value2);
    }
   
};