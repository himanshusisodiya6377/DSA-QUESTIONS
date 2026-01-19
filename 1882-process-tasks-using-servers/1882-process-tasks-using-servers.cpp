class Solution {
public:
    
    typedef pair<int,int> p;
    typedef pair<int,pair<int,int>> q;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        long long time=0;

        priority_queue<p,vector<p>,greater<p>>pq;//min weight free index
        priority_queue<q,vector<q>,greater<q>>t; //time min weight index
        
        vector<int>ans(m,0);

        for(int i=0;i<n;i++){
           pq.push({servers[i],i});
        }

        int idx=0;

        while(idx<m){

              while(!t.empty() && t.top().first<=time){
                pq.push(t.top().second);
                t.pop();
              }
              
              if(!pq.empty()){
              auto k=pq.top();
              pq.pop();

              ans[idx]=k.second;

              t.push({time+tasks[idx],k});
              idx++;
              time=max(time,(long long)idx);
              
              }
              else time=t.top().first;

        }

        return ans;
    }
};