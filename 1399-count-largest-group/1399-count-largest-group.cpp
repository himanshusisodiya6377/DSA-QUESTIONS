class Solution {
public:
    int getsum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++){
            int sum=getsum(i);
            mp[sum]++;
        }
        int s=INT_MIN;
        // for(auto v : mp){
        //     if(s<v.second) s=v.second;
        // }
        int ans=0;
        for(auto v : mp){
            if(v.second==s) ans++;
            else{
                if(v.second>s){
                    s=v.second;
                    ans=1;
                }
            }
        }
        return ans;
    }
};