class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans=0;
        for(int i=1;i<n;i++){
           arr[i]^=arr[i-1];
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0 && i>1) {
                ans+=i;
            }
            else if(arr[i]==0 && i<2) ans+=i;
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j] && j-i>2) ans+=(j-i-1);
                else if(arr[i]==arr[j]) ans+=(j-i-1);
            }
        }
        return ans;
    }
};