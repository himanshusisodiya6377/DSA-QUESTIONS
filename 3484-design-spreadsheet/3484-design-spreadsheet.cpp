class Spreadsheet {
public:
    vector<vector<int>> v;
    Spreadsheet(int rows) { v.resize(rows, vector<int>(26,0)); }

    void setCell(string cell, int value) {
        int c = cell[0] - 65;
        int r = stoi(cell.substr(1));
        v[r-1][c] = value;
        // cout<<r<<endl;
    }

    void resetCell(string cell) {
        int c = cell[0] - 65;
        int r = stoi(cell.substr(1));
        v[r-1][c] = 0;
    }

    int getValue(string formula) {
        string ans = formula.substr(1);
        vector<string> parts;

        stringstream ss(ans);
        string token;

        while (getline(ss, token, '+')) {
            parts.push_back(token);
        }
       
        

        int x,y;

        if(parts[0][0]>='A' && parts[0][0]<='Z'){
             int c = parts[0][0] - 65;
            //  cout<<c<<endl;
             int r = stoi(parts[0].substr(1));
            //  cout<<r<<endl;
             x=v[r-1][c];
        }
        else{
            x=stoi(parts[0]);
        }

        if(parts[1][0]>='A' && parts[1][0]<='Z'){
             int c = parts[1][0] - 65;
             int r = stoi(parts[1].substr(1));
             y=v[r-1][c];
        }
        else{
            y=stoi(parts[1]);
        }

        return x+y;
        // return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */