class Solution {
public:

   bool isvalid(int row,int col,vector<string>&temp){

       //checking for row
       for(int i=0;i<temp.size();i++){
           if(temp[row][i]=='Q') return false;
       }

       //checking coloumn
       for(int i=0;i<temp.size();i++){
        if(temp[i][col]=='Q') return false;
       }

       //checking digonal
       for(int i=0;i<temp.size();i++){
        if((row-i)>=0 && (col-i)>=0 && temp[row-i][col-i]=='Q') return false;
       }

       //checkinh anti diagonal
       for(int i=0;i<temp.size();i++){
        if((row-i)>=0 && (col+i)>=0 && temp[row-i][col+i]=='Q') return false;
       }

       return true;

   }
    
    void solve(int n, vector<vector<string>>&ans,vector<string>&temp,int row){

       if(row>=n){
        ans.push_back(temp);
        return;
       }

       
        for(int j=0;j<n;j++){
            if(isvalid(row,j,temp)){
                temp[row][j]='Q';
                solve(n,ans,temp,row+1);
                temp[row][j]='.';
            }
        }
       

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        solve(n,ans,temp,0);
        return ans;
    }
};