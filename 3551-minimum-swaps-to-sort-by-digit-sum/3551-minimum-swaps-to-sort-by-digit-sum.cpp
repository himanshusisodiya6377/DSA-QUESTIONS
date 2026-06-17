class Solution {
public:
    int digit(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>v;

        for(auto &it : nums){
            int sum=digit(it);
            v.push_back({sum,it});
        }

        sort(v.begin(),v.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });

        // for(auto &it : v){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums[i]]=i;

        int ans=0;

        for(int i=0;i<n;i++){
            if(mp[v[i][1]]==i) continue;
            ans++;
            int wrong_idx=mp[v[i][1]];
            int corr_idx=i;
            int temp=nums[i];
            swap(nums[wrong_idx],nums[corr_idx]);
            mp[temp]=wrong_idx;
            mp[v[i][1]]=corr_idx;
        }
        return ans;
    }
};