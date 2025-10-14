class Solution {
public:
    int binary_search(vector<int>&arr,int tar){
        int m=arr.size();
        int lo=0,hi=m-1;
        int ansmid=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            // cout<<lo<<" "<<mid<<" "<<hi<<endl;
            ansmid=mid;
            if(arr[mid]==tar) {
                 return mid;
            }
            else if(arr[mid]<tar) lo=mid+1;
            else hi=mid-1;
        }
        if(lo>=m) return ansmid;
        return lo;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int idx=binary_search(arr,x);
        // cout<<idx<<endl;
        int i,j;
        if(arr[idx]==x){
            i=idx;
            j=idx;
        } 
        else if((idx-1>=0) && abs(arr[idx-1]-x)<=abs(arr[idx]-x)){
              i=idx-1;
              j=idx-1;
        }
        else{
           i=idx,j=idx;
        }
        // vector<int>ans;
        while((j-i+1)!=k){
            if((i-1)>=0 && (j+1)<n){
                if(abs(arr[i-1]-x)<=abs(arr[j+1]-x)){
                    // ans.push_back(arr[i]);
                    i--;
                }
                else{
                    //  ans.push_back(arr[j]);
                     j++;
                }
            }
            else if((i-1)>=0){
                //  ans.push_back(arr[i]);
                i--;
            }
            else{
                //  ans.push_back(arr[j]);
                j++;
            }
        }
        // sort(ans.begin(),ans.end());
        // cout<<i<<" "<<j;
        vector<int>ans;
        for(int l=i;l<=j;l++){
            ans.push_back(arr[l]);
        }
        return ans;
    }
};