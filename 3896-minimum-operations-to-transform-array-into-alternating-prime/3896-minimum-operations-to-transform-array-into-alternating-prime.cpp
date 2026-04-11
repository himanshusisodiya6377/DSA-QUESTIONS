class Solution {
public:
    static vector<int>prime;
    static bool flag;
    static vector<bool>seive;

    static void prime_seive(int n){
        // cout<<"yes"<<endl;
        if(flag) return;
        flag=true;
        prime.clear();
        seive.assign(n+1,true);
        seive[0]=seive[1]=false;

        for(int i=2;i*i<=n;i++){
            if(seive[i]==false) continue;
            
                for(int j=i*i;j<=n;j+=i){
                    seive[j]=false;
            
            }
        }

        for(int i=0;i<=n;i++){
            if(seive[i]==true) prime.push_back(i);
        }
    }
    int minOperations(vector<int>& nums) {
        if(!flag) prime_seive(1000001);

        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                //prime  
                if(!seive[nums[i]]){
                    auto it=lower_bound(prime.begin(),prime.end(),nums[i]);
                    if(it!=prime.end()){
                        ans+=(*it)-nums[i];
                    }
                } 
            }
            else{
                //odd
                if(seive[nums[i]]){
                    if(nums[i]==2) ans+=2;
                    else ans++;
                }
            }
        }

        return ans;
    }
};
vector<int> Solution::prime;
vector<bool> Solution::seive;
bool Solution::flag = false;