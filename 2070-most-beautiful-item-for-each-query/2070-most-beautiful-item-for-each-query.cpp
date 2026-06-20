class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        vector<int>ans(queries.size(),0);

        sort(items.begin(),items.end());

        // for(auto &it : items){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        // unordered_map<int,vector<int>>mp;
        vector<pair<int,int>>v;

        for(int i=0;i<queries.size();i++){
            v.push_back({queries[i],i});
        }

        // for(int i=0;i<queries.size();i++) mp[queries[i]].push_back(i);
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        // int maxi=0;
        int i=0,j=0;

        while(i<n && j<queries.size()){
            
            while(i<n && items[i][0]<=v[j].first){
                // maxi=max(maxi,items[i][1]);
                pq.push(items[i][1]);
                i++;
            }
            // i++;
            // for(auto &it : mp[queries[j]]){
            // ans[it]=maxi;
            // }
            // cout<<i<<" "<<queries[j]<<" "<<maxi<<endl;
            ans[v[j].second]=(pq.empty() ? 0 : pq.top());
            j++;
            // while(j<queries.size() && queries[j]==queries[j-1]) j++;
            // j++;
        }

        while(j<queries.size()){
            // for(auto &it : mp[queries[j]]){
            // ans[it]=maxi;
            // }
             ans[v[j].second]=(pq.empty() ? 0 : pq.top());
            j++;
            //  while(j<queries.size() && queries[j]==queries[j-1]) j++;
        }
        return ans;
    }
};