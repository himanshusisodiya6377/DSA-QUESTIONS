class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();

        int xr_sec=0;
        for(auto &it : arr2) xr_sec^=it;

        int ans=0;
        for(auto &it : arr1){
            int y=it&xr_sec;
            ans^=y;
        }

        return ans;
    }
};