class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();

        int maxProd = arr[0];
        int minProd = arr[0];
        int ans = arr[0];

        for(int i = 1; i < n; i++) {
            if(arr[i] < 0)
                swap(maxProd, minProd);

            maxProd = max(arr[i], maxProd * arr[i]);
            minProd = min(arr[i], minProd * arr[i]);

            ans = max(ans, maxProd);
        }
        return ans;
    }
};