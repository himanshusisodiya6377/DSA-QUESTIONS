class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>ans;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
            set<pair<int,int>> vis;
            vis.insert({0,0});
            
        while(k>0 && !pq.empty()){
          auto p=pq.top();
          pq.pop();
          k--;
          int x=p.second[0];
          int y=p.second[1];
          ans.push_back({nums1[x],nums2[y]});
        //   int sum1=INT_MIN;
        //   int sum2=INT_MIN;
          if(x<n-1 && !vis.count({x+1,y})){
             int sum1=nums1[x+1]+nums2[y];
             pq.push({sum1,{x+1,y}});
             vis.insert({x+1,y});
          }
          if(y<m-1 && !vis.count({x,y+1})){
            int sum2=nums1[x]+nums2[y+1];
             pq.push({sum2,{x,y+1}});
            vis.insert({x,y+1});
          }       
          
        }
        return ans;
    }
};