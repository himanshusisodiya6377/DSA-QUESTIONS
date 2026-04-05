class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq;
        for(auto &it : stones) pq.push(it);
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            if(x==pq.top()) pq.pop();
            else{
                int y=pq.top();
                pq.pop();
                pq.push(abs(y-x));
            }
        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};