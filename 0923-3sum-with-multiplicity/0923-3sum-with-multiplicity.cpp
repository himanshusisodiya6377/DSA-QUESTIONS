class Solution {
public:
    int mod=1e9+7;
    int threeSumMulti(vector<int>& nums, int target) {
        int n=nums.size();
        // vector<vector<int>>ans;
        // if(n<3) return ans;
        int ans=0;
        // set<vector<int>>st;

        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            // vector<int>v;
            // if(i>0 && nums[i]==nums[i-1]) continue;
           
                // if(j==i) continue;
               
                int k=i+1,l=n-1;
                
                while(k<l){
                     long long sum=1LL*nums[i]+nums[k]+nums[l];
                     if(sum==target){
                        // ans.push_back({nums[i],nums[k],nums[l]});
                        int cnt1=1,cnt2=1;
                        while(k<l-1 && nums[k]==nums[k+1]) {
                            k++;
                            cnt1++;
                        }
                        while(k+1<l && nums[l]==nums[l-1]) {
                            l--;
                            cnt2++;
                        }
                        int x=cnt1+cnt2;
                        
                        if(nums[k]==nums[l]) ans+=((x)*(x-1)/2)%mod;
                        else ans = (ans + 1LL*cnt1*cnt2)%mod;
                        ans=ans%mod;
                        k++;
                        l--;

                     }
                     else if(sum>target) l--;
                     else k++;
                    }
                
            
        }

        // for(auto &it : st) ans.push_back(it);
        return ans;
    }
};