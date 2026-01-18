class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int n=arr.size();
        
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;
        // unordered_map<int,int>idx;
        for(int i=0;i<n;i++) {
            mp[arr[i]]=i;
            // idx[i]=ele;
           pq.push(arr[i]);
        }
        
        int i=0;
        int swaps=0;
        while(i<n){
            while(i<n && arr[i]==pq.top()){
                i++;
                pq.pop();
            }
            if(pq.empty()) break;
            swap(arr[i],arr[mp[pq.top()]]);
        // for(auto &it : arr) cout<<it<<" ";
            // cout<<endl;
            mp[arr[mp[pq.top()]]]=mp[pq.top()];
            mp[arr[i]]=i;
            swaps++;
            // i++;
        }
        return swaps;
    }
};