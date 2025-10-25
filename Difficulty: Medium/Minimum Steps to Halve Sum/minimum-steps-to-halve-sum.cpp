class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        int n=arr.size();
        priority_queue<double>pq;
        double sum=0;
        for(auto it : arr){
            sum+=it;
            pq.push(it);
        }
        double step=0;
        double half=sum/2;
        while(!pq.empty() && sum>half){
            sum-=pq.top()/2;
            double x=pq.top();
            pq.pop();
            pq.push(x/2);
            step++;
        }
        return step;
    }
};