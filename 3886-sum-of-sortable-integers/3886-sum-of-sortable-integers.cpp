class Solution {
public:
    bool cycle(vector<int>&nums,int i,int j,int p){
        int less=0,up=0;
        int n=nums.size();
        int jump=i+p;
        for(int k=i;k<=j;k++){
            int prev = (k == i) ? j : k - 1;
            int next = (k == j) ? i : k + 1;
            if(nums[k]<nums[prev] && nums[k]>nums[next]) {
                return false; //n-j-1
            }
            else if(nums[k]>=nums[prev] && nums[k]>nums[next]){
                if(up==0) up=1;
                else return false;
            } 
            else if(nums[k]<nums[prev] && nums[k]<=nums[next]){
            // cout<<"yes"<<" "<<jump<<endl;
                if(less==0) less=1;
                else return false;
            }
            else if(nums[k]>=nums[prev] && nums[k]<=nums[next]) continue;
            else return false;
        }

        return true;
    }
    bool final_check(vector<int>nums,int k){
        int i=0,j=k-1;
        vector<int>t=nums;
        sort(t.begin(),t.end());

        if(t==nums) return true;

        while(j<nums.size()){
            sort(nums.begin()+i,nums.begin()+j+1);
            i+=k;
            j+=k;
        }

        // for(auto &it : nums) cout<<it<<" ";
        // cout<<endl;
        // cout<<k<<endl;
        return (nums==t);
    }
    bool check(vector<int>&nums,int k){
        int i=0,j=k-1;

        while(j<nums.size()){
                // cout<<i<<" "<<j<<endl;
            if(cycle(nums,i,j,k)){
                i+=k;
                j+=k;
            }
            else return false;
        }

        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();

        int ans=0;
        vector<int>t=nums;
        sort(t.begin(),t.end());

        if(t==nums) ans++;
        for(int i=2;i<=n;i++){
            if(n%i==0 && check(nums,i) && final_check(nums,i)) ans+=i;
        }

        return ans;
    }
};