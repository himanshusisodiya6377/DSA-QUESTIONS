class Solution {
public:
         
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

    bool isvalid(int x,int y,vector<vector<char>>& board){
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size()) return false;
        return true;
    }
 
    bool solve(vector<vector<char>>& board,string word,vector<vector<bool>>&visit,int n,int i,int j){

       if(n>=word.length()) return true;

       if(board[i][j]!=word[n]) return false;

       for(auto it : dir){

       int r=i+it.first;
       int c=j+it.second;

       if(isvalid(r,c,board) && visit[r][c]!=true){
        visit[r][c]=true;
        if(solve(board,word,visit,n+1,r,c)) return true;
        visit[r][c]=false;
       }

       }


       return false;
 

    }

    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>>visit(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                visit[i][j]=true;
                if(solve(board,word,visit,0,i,j)) return true;
                visit[i][j]=false;
                }
            }
        }
        return false;
    }
};