class Solution {
public:
    long long mod=1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int left=0,right=0;
            int k=i;
            //left count
            while( k>=1 && arr[k-1]>arr[i]){
                 k--;
                 left++;
            }
            //right count
            k=i;
            while( k<n-1 && arr[k+1]>=arr[i]){
                k++;
                right++;
            }
            int size=(((left+1)%mod)*((right+1)%mod))%mod;
            ans+=((size%mod)*(arr[i]%mod))%mod;
            ans=ans%mod;
        }
        return ans;
    }
};

/* 
Intuition
To arrive at the solution, we must track two things for each element arr[i]:

left[i]: the index of the first smaller element to the left of arr[i]
right[i]: the index of the first element that is less than or equal to arr[i] to the right
With left[i] and right[i] determined, the number of subarrays in which arr[i] is the minimum can be calculated by (1 + num_left) * (num_right + 1).
*/