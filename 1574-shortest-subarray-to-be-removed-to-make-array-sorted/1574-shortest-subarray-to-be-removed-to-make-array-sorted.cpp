class Solution {
public:
    // bool inc(vector<int>&arr,int start,int end){
    //     int n=arr.size();

    //     stack<int>st;

    //     int i=0;
    //     while(i<n){
    //         while(i>=start && i<=end) i++;
    //         if(i>=n) break;
    //         if(st.empty()) st.push(arr[i]);
    //         else{
    //             if(st.top()>arr[i]) return false;
    //             else st.push(arr[i]);
    //         }
    //         i++;
    //     }

    //     return true;
    // }
    vector<int>pre,suff;
    bool inc(vector<int>&arr,int i,int j){
        int n=arr.size();
        // cout<<i<<" "<<j<<endl;
        if(i==0){
            if(j<n-1 && suff[j+1]==-1) return true;
            else if(j==n-1) return true;
        }
        else if(j==n-1){
            if(i>0 && pre[i-1]==1) return true;
            else if(i==0) return true;
        }
        else{
            if(pre[i-1]==1 && suff[j+1]==-1 && arr[i-1]<=arr[j+1]) return true;
         }
         return false;
    }
    bool check(vector<int>&arr,int len){
        if(len==0 && pre[arr.size()-1]==1) return true;
        else if(len==0) return false;
        int i=0,j=len-1;
        int n=arr.size();
        // bool flag=false;
        while(j<n){
            if(inc(arr,i,j)) return true; 
            i++;
            j++;
        }

        return false;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int lo=0,hi=n-1;
        int ans=n;
        pre.resize(n,-1);
        suff.resize(n,1);

        //lets fill pre
        pre[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]) pre[i]=1;
            else break;
        }

        suff[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1]) suff[i]=-1;
            else break;
        }
        // for(auto &it: pre) cout<<it<<" ";
        // cout<<endl;

        // for(auto &it : suff) cout<<it<<" ";
        // cout<<endl;
        
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);

            if(check(arr,mid)){
                ans=mid;
                // cout<<mid<<endl;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
    }
};