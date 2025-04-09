class Solution {
public:
    bool canSortArray(vector<int>& arr) {
          bool swapped;
          int n=arr.size();
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                if(__builtin_popcount(arr[j])==__builtin_popcount(arr[j+1])){
                swap(arr[j], arr[j + 1]);
                swapped = true;
                }
                else return false;
            }
        }
        if (!swapped) break;
    }
    return true;
    }
};