class Solution {
public:
//interesting question
    int leastInterval(vector<char>& tasks, int n) {
        // int n=tasks.size();
        unordered_map<char,int>mp;
        for(auto &it : tasks) mp[it]++;
        priority_queue<int>pq;
        for(auto &it : mp) pq.push(it.second);
        int gap=pq.top()-1;
        pq.pop();
        int idle=n*gap;
        while(!pq.empty()){
            idle-=min(gap,pq.top());
            pq.pop();
        }
        if(idle<=0) return tasks.size();
        return tasks.size()+idle;
    }
};