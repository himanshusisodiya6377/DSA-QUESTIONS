// class Solution {
// public:     int countsubset(vector<int>& nums, int target) {
//         int n=nums.size();
      
//         //intialisation
//          vector<vector<int>>t(n+1,vector<int>(target+1,0));
//         for (int i = 0; i <= n; i++) t[i][0] = 1;
         
//         for(int i=1;i<n+1;i++){
//             for(int j=0;j<target+1;j++){
//                 if(nums[i-1]<=j){
//                     t[i][j]=t[i-1][j] + t[i-1][j-nums[i-1]];
//                 }
//                 else t[i][j]=t[i-1][j];
                
//             }
//         }
//       return t[n][target];
//     }
//     int findTargetSumWays(vector<int>& arr, int target) {
//        int n=arr.size();
//         if (n == 1 && arr[0]!=0) {
//     return (arr[0] == abs(target) || -arr[0] == abs(target)) ? 1 : 0;
// }
//      int sum=0;
//      for(auto v : arr) sum+=v;
//      //initialization
//      if (sum < target || (sum + target) % 2 != 0) return 0;
//      int tar=(sum+target)/2;
//      return countsubset(arr,tar);
//     }
// };
class Solution {
public:
    int countsubset(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= n; i++) t[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] <= j)
                    t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[n][target];
    }

    int findTargetSumWays(vector<int>& arr, int target) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum < abs(target) || (sum + target) % 2 != 0) return 0;
        int tar = (sum + target) / 2;
        return countsubset(arr, tar);
    }
};
