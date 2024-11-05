class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        //intializing variables
        int i=1,j=i+k-1,count=0,psum=0,csum=0;
        //first k sum
     
        if(k==1){
            for(int l=0;l<n;l++){
                if(arr[l]>=threshold) count++;
            }
        }
        else{
        for(int m=0;m<k;m++){
            psum+=arr[m];
        }
        if((psum/k)>=threshold) count++;
        //sliding window
        while(j<n){
            csum=psum+arr[j]-arr[i-1];
           if((csum/k)>=threshold) count++;
           i++;
           j++;
           psum=csum;
        }
        }
        return count;
    }
};