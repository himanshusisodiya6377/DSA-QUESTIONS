class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pro, vector<int>& cap) {
        int n=pro.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({cap[i],pro[i]});
        }

        sort(v.begin(),v.end());

        int i=0;
        int ans=w;
        
        priority_queue<int>pq;
        while(k>0){
            while(i<n && v[i].first<=ans){
                pq.push(v[i].second);
                i++;
            }
            // cout<<pq.size()<<endl
            if (pq.empty()) break; 
            ans+=pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};