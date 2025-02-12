class Solution {
public:
    int reverse(int n){
         int rev=0;
           while(n>0){
            int digit=n%10;
            n/=10;
            rev+=digit;
            rev*=10;
           }
           return rev/10;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            int rev=reverse(nums[i]);
            s.insert(rev);         
        }

    return s.size();
    }

};