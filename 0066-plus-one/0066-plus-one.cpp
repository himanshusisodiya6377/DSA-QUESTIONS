class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>ans;
        int num=0;
        for(int i=0;i<n;i++){
            num=num*10+digits[i];
        }
        // cout<<num+1<<endl;
        num=num+1;
        while(num>0){
            ans.push_back(num%10);
            num/=10;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};