class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> dir = {
        {0,1},   // 1 -> Right
        {0,-1},  // 2 -> Left
        {1,0},   // 3 -> Down
        {-1,0}   // 4 -> Up
    };

    bool check(int x,int y,int m,int n){
        return x>=0 && x<m && y>=0 && y<n;
    }

    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){

            auto cur = pq.top();
            pq.pop();

            int cost = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            if(cost > dist[x][y])
                continue;

            for(int i=0;i<4;i++){

                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(!check(nx,ny,m,n))
                    continue;

                int wt = (grid[x][y] == i+1) ? 0 : 1;

                if(dist[x][y] + wt < dist[nx][ny]){

                    dist[nx][ny] = dist[x][y] + wt;
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }

        return dist[m-1][n-1];
    }
};