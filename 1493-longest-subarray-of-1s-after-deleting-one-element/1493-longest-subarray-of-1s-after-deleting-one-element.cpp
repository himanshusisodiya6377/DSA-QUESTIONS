class Solution {
public:
    int longestSubarray(vector<int>& nums) {
     int n=nums.size();
     int i,j;
     for(int k=0;k<n;k++){
        if(nums[k]==1){
            i=k;
            j=k;
            break;
        }
     }
     int maxi=INT_MIN;
     int length=0;
     int count=1;
     while(j<n){
        if(nums[j]==1){
            j++;
            length++;
        }
        else{
            if(count==1){
                j++;
                count--;
            }
            else{
                maxi=max(maxi,length);
                while(nums[i]!=0){
                    i++;
                    length--;
                }
                i++;
                count++;
            }
        }
     }   
     maxi=max(maxi,length);
     if(maxi==n) return n-1;
     return maxi;
    }
};