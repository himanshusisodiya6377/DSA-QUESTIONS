class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        vector<pair<int,int>>v;
        
        int n=start.size();
        
        for(int i=0;i<n;i++) v.push_back({start[i],end[i]});
        
        sort(v.begin(),v.end());
        
        // for(auto &it : v) cout<<it.first<<" "<<it.second<<endl;
        
        int cnt=0;
       
        priority_queue<int,vector<int>,greater<int>>pq;
        
        // int e=v[0].second;
        
        for(int i=0;i<n;i++){
            bool flag=false;
            if(!pq.empty() && pq.top()<=v[i].first){
                flag=true;
                pq.pop();
            }
            
            if(!flag) cnt++;
            
            pq.push(v[i].second);
        }
        
        return cnt;
    }
};
