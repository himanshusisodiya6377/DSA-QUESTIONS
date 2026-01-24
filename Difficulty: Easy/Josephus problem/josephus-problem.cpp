class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        deque<int>dq;
        
        for(int i=1;i<=n;i++) dq.push_back(i);
        
        while(dq.size()>1){
            int temp=k-1;
            while(!dq.empty() && temp>0){
                int x=dq.front();
                // cout<<x<<endl;
                dq.pop_front();
                dq.push_back(x);
                temp--;
            }
            dq.pop_front();
        }
        return dq.front();
    }
};