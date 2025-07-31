class Solution {
public:

    typedef pair<int,pair<int,int>> p;

     bool issafe(int x,int y,vector<vector<int>>& grid){
        if((x>=0 && x<grid.size()) && (y>=0 && y<grid[0].size())) return true;
        return false;
    }
  
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int r=grid.size();
       int c=grid[0].size();
       if(r==1 && c==1 && grid[r-1][c-1]==0) return 1; 
       if(grid[0][0]==1 || grid[r-1][c-1]==1) return -1;
       vector<vector<int>>dist(r,vector<int>(c,INT_MAX));
       //mark it 1
       dist[0][0]=0;
       vector<pair<int,int>>path={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
       priority_queue<p,vector<p>,greater<p>>pq;
       pq.push({1,{0,0}});

       while(!pq.empty()){
        auto v =pq.top();
        pq.pop();
        int x=v.second.first;
        int y=v.second.second;
        int wt=v.first;

        for(auto dir : path){
            int _x=x+dir.first;
            int _y=y+dir.second;

            if(issafe(_x,_y,grid) && grid[_x][_y]==0 && (wt+1<dist[_x][_y])){
                dist[_x][_y]=wt+1;
                pq.push({dist[_x][_y],{_x,_y}});
                // grid[_x][_y]=1;
            }
        }
       }
       //here creating problem
       return dist[r-1][c-1] == INT_MAX ? -1 : dist[r-1][c-1];

    }
};