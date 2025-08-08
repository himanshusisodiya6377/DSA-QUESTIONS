class Solution {
  public:
  
  vector<pair<char,pair<int,int>>>dir={{'D',{1,0}},{'L',{0,-1}},{'R',{0,1}},{'U',{-1,0}}};

  
    bool isvalid(int x,int y,vector<vector<int>>&maze){
        if(x<0 || y<0 || x>=maze.size() || y>=maze.size()) return false;
        return true;
    }
  
    void solve(vector<vector<int>>&maze,vector<string>&ans,string &temp,vector<vector<bool>>&visit,int row,int col){
        
        if(row==(maze.size()-1) && col==(maze.size()-1)){
            ans.push_back(temp);
            return;
        }        
        
        for(auto it : dir){
            
            char dire=it.first;
            int r=row+it.second.first;
            int c=col+it.second.second;
            
            if(isvalid(r,c,maze) && visit[r][c]==false && maze[r][c]!=0){
                visit[r][c]=true;
                temp.push_back(dire);
                solve(maze,ans,temp,visit,r,c);
                visit[r][c]=false;
                temp.pop_back();
            }
            
        }
        
        
        
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n=maze.size();
        if(maze[0][0]==0 || maze[n-1][n-1]==0) return {};
        vector<string>ans;
        string temp="";
        vector<vector<bool>>visit(n,vector<bool>(n,false));
        visit[0][0]=true;
        solve(maze,ans,temp,visit,0,0);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};