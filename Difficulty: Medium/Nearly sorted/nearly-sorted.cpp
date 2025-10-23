class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        while(i<n){
            pq.push(arr[i]);
            i++;
        }
        i=0;
        while(!pq.empty()){
            arr[i]=pq.top();
            pq.pop();
            i++;
        }
    }
};