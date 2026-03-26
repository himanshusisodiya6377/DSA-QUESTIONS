class Solution {
public:
    void Update(int number,vector<int>&vec,int toggle){        
        for(int i=0;i<32;i++){
            if((number >> i) & 1){
                vec[i]=vec[i]+toggle;
            }
        }
    }

    int BinaryToInteger(vector<int>&vec){
        int num=0;

        for(int i=0;i<32;i++){
            if(vec[i]>0){
                num = num | (1<<i);
            }
        }

        // cout<<num<<endl;

        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;

        vector<int>vec(32,0);
        int ans=INT_MAX;
        while(j<n){

            Update(nums[j],vec,1);
            while(i<=j && BinaryToInteger(vec)>=k){
                ans=min(ans,j-i+1);
                Update(nums[i],vec,-1);
                i++;
            }

            j++;
        }

        return ans==INT_MAX ? -1 : ans;
    }
};