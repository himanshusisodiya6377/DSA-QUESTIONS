class Solution {
public:
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    int minimumTime(vector<vector<int>>& grid) {
         if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        int r=grid.size();
        int c=grid[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        q.push({grid[0][0],0,0});

        vector<vector<bool>>visit(r,vector<bool>(c,false));
        // visit[0][0]=true;

        while(!q.empty()){
            auto p=q.top();
            q.pop();
            
            int x=p[1];
            int y=p[2];
            int time=p[0];

            if(x==r-1 && y==c-1) return time;

            if(visit[x][y]) continue;
            visit[x][y]=true;

            for(auto &it : dir){
                int new_x=x+it.first;
                int new_y=y+it.second;
                
                if(new_x>=0 && new_x<r && new_y>=0 && new_y<c){
                    int wt=(grid[new_x][new_y]-time)%2==0;
                    q.push({max(grid[new_x][new_y]+wt,time+1),new_x,new_y});
                    // visit[]
                }
            }

        }
        return -1;
    }
};