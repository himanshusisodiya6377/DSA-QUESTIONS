class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        
        vector<int>ans;
        
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>st;
        
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        
        
        pq.push({a[0]+b[0],{0,0}});
        st.insert({0,0});
        // ans.push_back(a[0]+b[0]);
        
        while(!pq.empty() && ans.size()<k){
            
            auto p=pq.top();
            pq.pop();
            
            ans.push_back(p.first);
            
            int i=p.second.first;
            int j=p.second.second;
            
            if(i+1<n && st.find({i+1,j})==st.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                st.insert({i+1,j});
            }
            
            if(j+1<n && st.find({i,j+1})==st.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                st.insert({i,j+1});
            }
            
            
        }
        
        return ans;
    }
};