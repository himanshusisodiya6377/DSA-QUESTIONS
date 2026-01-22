// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++) pq.push({arr[i],i});
        
        int sz=pq.size()-1;
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            
            int idx=p.second;
            
            if(abs(sz-idx)>k) return "No";
            
            sz--;
        }
        return "Yes";
    }
};