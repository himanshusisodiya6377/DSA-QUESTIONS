class Solution {
public:
    void Update(int num,vector<int>&v,int toggle){
         for(int i=0;i<32;i++){
            if((num>>i)&1){
                v[i]=v[i]+toggle;
            }
         }
    }
    int BinaryToInterger(vector<int>&v){
        int num=0;

        for(int i=0;i<32;i++){
            if(v[i]>0){
                num=num | (1<<i);
            }
        }

        return num;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();

        int max_or=0;
        vector<int>maxi(32,0);

        for(auto &it : nums){
            for(int i=0;i<32;i++){
                if((it>>i)&1) maxi[i]++;
            }
        }

        for(auto &it : nums) max_or|=it;

        int i=0,j=0;
        vector<int>ans(n,0);
        
        vector<int>v(32,0);
        while(j<n){
           Update(nums[j],v,1);

           while(i<=j && BinaryToInterger(v)==max_or){
            // cout<<BinaryToInterger(v)<<endl;
            Update(nums[i],v,-1);
            Update(nums[i],maxi,-1);

            max_or=BinaryToInterger(maxi);
            ans[i]=j-i+1;
            // cout<<"yes"<<endl;
            // cout<<i<<" "<<j<<endl;
            i++;
            //   cout<<BinaryToInterger(v)<<endl;
           }

           j++;
        }

        while(i<n){
            ans[i]=j-i+1;
            i++;
        }

        return ans;
    }
};