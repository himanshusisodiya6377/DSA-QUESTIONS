class Solution {
public:
  
    bool issafe(int x,int y,vector<vector<int>>& heights){
        if((x>=0 && x<heights.size()) && (y>=0 && y<heights[0].size())) return true;
        return false;
    }
    
    typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>>dist(r,vector<int>(c,INT_MAX));
        dist[0][0]=0;
        vector<pair<int,int>>path={{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto v =pq.top();
            int x=v.second.first;
            int y=v.second.second;
            int wt=pq.top().first;
            pq.pop();

            for(auto dir : path){
                int _x=x+dir.first;
                int _y=y+dir.second;

                if(issafe(_x,_y,heights)){
                   int newEffort = max(wt, abs(heights[_x][_y] - heights[x][y]));

                    if (newEffort < dist[_x][_y]) {
                          dist[_x][_y] = newEffort;
                           pq.push({newEffort, {_x, _y}});
                    }
                    
                }
            }
        }
        return dist[r-1][c-1];
    }
};