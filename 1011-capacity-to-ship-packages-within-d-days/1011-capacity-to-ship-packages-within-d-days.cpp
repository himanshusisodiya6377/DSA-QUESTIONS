class Solution {
public:
    bool helper(int mid,vector<int>& weights,int days){
        int count = 1, sum = 0;
        
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {
                count++;
                sum = weights[i];
            }
        }
        if (count <= days)
            return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCapacity=0;
        int n = weights.size();
        
        for(int i = 0; i < n; i++)
            maxCapacity += weights[i];
        
        int low = *max_element(weights.begin(), weights.end()), high=maxCapacity;
        int result;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (helper(mid, weights, days)) {
                result = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return result;
    }
};

// class Solution {
// public:
//     int check(vector<int>v,int n){
//       int count=1;//check it
//       int temp=0;
//       for(int i=0;i<v.size();i++){
//          if(temp>n) {
//             count++;
//             temp=v[i];
//          }
//          else temp+=v[i];
//       }
//       return count;
//     } 
//     int shipWithinDays(vector<int>& weights, int days) {
//      long long n=weights.size();
//      long long max=INT_MIN;
//      long long sum=0;
//      for(int i=0;i<n;i++){
//         if(max<weights[i]) max=weights[i];
//           sum+=weights[i];
//      }
//      long long lo=max,hi=sum;
//      long long mini=INT_MAX;
//      while(lo<=hi){
//         long long mid=(lo+hi)/2;
//         long long x=check(weights,mid);
//         if(x<=days){
//             mini=mid;
//             hi=mid-1;
//         }
//         // else if(x<days) hi=mid-1;
//         else lo=mid+1; 
//      }
//      if(mini==INT_MAX) return (int)max;
//      else return (int)mini;
//     }
// };