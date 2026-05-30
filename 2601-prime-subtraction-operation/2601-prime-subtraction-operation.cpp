class Solution {
public:
    vector<bool>prime;
    bool flag=false;
    bool check(int n){
        if(n==2) return true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    vector<int>finale;
    void prime_identify(){
        for(int i=0;i<prime.size();i++){
            if(prime[i]) finale.push_back(i);
        }
    }
    void seive(){
        flag=true;
        prime.resize(2001,true);
        prime[0]=prime[1]=false;

        for(int i=2;i<prime.size();i++){
            if(check(i)){
                for(int j=i*i;j<prime.size();j+=i){
                    prime[j]=false;
                }
            }
        }
        prime_identify();
    }
    
    bool primeSubOperation(vector<int>& nums) {
        if(!flag) seive();
        // for(auto &it : finale){
        //     cout<<it<<" ";
        // }
        int n=nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]) continue;
            else{
                int diff=nums[i-1]-nums[i];
                diff++;
                auto it =lower_bound(finale.begin(),finale.end(),diff);
                if(*it>=nums[i-1]) return false;
                nums[i-1]-=*it;
             }
        }
        return 1;
    }
};