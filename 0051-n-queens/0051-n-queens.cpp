class Solution {
public:
    unordered_set<int> r;
    unordered_set<int> c;
    unordered_set<int> dig;
    unordered_set<int> anti_dig;

    bool isvalid(int row, int col, vector<string>& temp) {

        // checking for row
        // for (int i = 0; i < temp.size(); i++) {
        //     if (temp[row][i] == 'Q')
        //         return false;
        // }
        if(r.find(row)!=r.end()) return false;

        // checking coloumn
        // for (int i = 0; i < temp.size(); i++) {
        //     if (temp[i][col] == 'Q')
        //         return false;
        // }
        if(c.find(col)!=c.end()) return false;


        // checking digonal
        // for (int i = 0; i < temp.size(); i++) {
        //     if ((row - i) >= 0 && (col - i) >= 0 &&
        //         temp[row - i][col - i] == 'Q')
        //         return false;
        // }
        if(dig.find(row+col)!=dig.end()) return false;

        // checkinh anti diagonal
        // for (int i = 0; i < temp.size(); i++) {
        //     if ((row - i) >= 0 && (col + i) >= 0 &&
        //         temp[row - i][col + i] == 'Q')
        //         return false;
        // }
        if(anti_dig.find(row-col)!=anti_dig.end()) return false;
        

        return true;
    }

    void solve(int n, vector<vector<string>>& ans, vector<string>& temp,
               int row) {

        if (row >= n) {
            ans.push_back(temp);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isvalid(row, j, temp)) {
                temp[row][j] = 'Q';
                r.insert(row);
                c.insert(j);
                dig.insert(row+j);
                anti_dig.insert(row-j);
                solve(n, ans, temp, row + 1);
                temp[row][j] = '.';
                r.erase(row);
                c.erase(j);
                dig.erase(row+j);
                anti_dig.erase(row-j);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        solve(n, ans, temp, 0);
        return ans;
    }
};