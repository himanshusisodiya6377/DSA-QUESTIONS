// class Solution {
// public:
//     long long countGood(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_map<int, int> mp;
//         int i = 0, j = 0;
//         int ans = 0;
//         int count = 0;
//         int first=-1,second;
//         while (j < n) {
//             if(mp.find(nums[j])!=mp.end()){
//                 first=mp[nums[j]];
//             }
//            mp[nums[j]]++;
//            second=mp[nums[j]];
//            if(first!=-1) count+=(second*(second-1)/2)-(first*(first-1)/2);  
//            else {
//             count=count+second*(second-1)/2;
//            first=-1;
//            }
//            if(count>=k){
//                ans=ans+1+(n-j-1);
//                 while(count>=k){
//                     int fir=mp[nums[i]];
//                     mp[nums[i]]--;
//                     int x=mp[nums[i]];
//                     int sec=x*(x-1)/2;
//                     int diff=(fir*(fir-1)/2)-sec;
//                     count-=diff;
//                     if(count<k){
//                       i++;
//                      break;
//                     } 
//                     ans=ans+1;
//                     i++;
//                 }
//            }
//            j++;
//         }
//         return ans;
//     }
//         };
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        long long ans = 0;
        long long count = 0;

        while (j < n) {
            int freqBefore = mp[nums[j]];
            mp[nums[j]]++;
            count += freqBefore;

            while (count >= k) {
                ans += (n - j);
                count -= (mp[nums[i]] - 1);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }

        return ans;
    }
};