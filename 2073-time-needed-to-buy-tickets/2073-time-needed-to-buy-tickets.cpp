class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0;i<tickets.size();i++){
            if(k==i) q.push({tickets[i],i});
            else  q.push({tickets[i],-1});
        }
        int time=1;
        while(!q.empty()){
            auto p=q.front(); q.pop();
            if(p.second!=-1 && p.first==1) return time;
            time++;
            if(p.first>1) q.push({p.first-1,p.second});
        }

        return -1;
    }
};