class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        priority_queue<pair<int,int>>pq; //value index
        
        int n=arr.size();
        vector<int>ans;
        
        int i=0,j=0;
        while(j<n){
            pq.push({arr[j],j});
            
            if(j-i+1==k){
                while(!pq.empty() && pq.top().second<i) pq.pop();
                ans.push_back(pq.top().first);
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};