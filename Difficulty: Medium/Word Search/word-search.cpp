class Solution {
  public:
   vector<pair<int,int>>dist={{1,0},{0,1},{-1,0},{0,-1}};
   bool backtrack(int i,int j,int idx,string &word,int row,int col,vector<vector<char>> &mat){
       if(i<0 || i>=row || j<0 || j>=col || mat[i][j]=='#') return false;
       
       if(mat[i][j]!=word[idx]) return false;
       
       if(idx==word.size()-1) return true;
       
       
       
       char temp=mat[i][j];
       
       mat[i][j]='#';
       for(auto &it : dist){
                    int x=i+it.first;
                    int y=j+it.second;
                    if(backtrack(x,y,idx+1,word,row,col,mat)) return true;
                    }
                    
        mat[i][j]=temp;
                    
        return false;
       
   }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int r=mat.size();
        int c=mat[0].size();
        
        int n=word.size();
        
        // vector<vector<bool>>visit(r,vector<bool>(c,false));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               if(mat[i][j]==word[0]){
               if(backtrack(i,j,0,word,r,c,mat)) return true;
               }
            }
        }
        
        return false;
    }
};