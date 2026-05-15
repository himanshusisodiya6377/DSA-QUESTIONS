class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // int c=board[0].size();
        int sz = n * n;
        unordered_map<int, int> st; // position nxt
        bool flag = false;
        if (n % 2 == 0)
            flag = true;

        for (int i = 0; i < n; i++) {
            if (flag) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != -1) {
                        st[sz] = board[i][j];
                    }
                    // cout<<sz<<endl;
                    sz--;
                }
                flag = false;
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] != -1) {
                        st[sz] = board[i][j];
                    }
                    // cout<<sz<<endl;
                    sz--;
                }
                flag = true;
            }
        }

        // for (auto it : st) {
        //     cout << it.first << " " << it.second << endl;
        // }
        // cout << ":" << endl;
        // sz = n * n;
        queue<pair<int, int>> q;
        q.push({1, 0});

        unordered_set<int> vis;
        vis.insert(1);

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int pos = p.first;
            int move = p.second;
            // cout << pos << " " << move << "*" << endl;
            if (pos == n * n)
                return move;

            // if (st.find(pos) != st.end()) {
            //     q.push({st[pos], move});
            //     // vis.insert(st[pos]);
            // }
            for (int i = 1; i <= 6; i++) {
                
                    // if(pos+i==n*n) return move+1;
                    // cout<<pos+i<<endl;
                    int next = pos + i;
                    if (next > n * n)
                        break;

                    if (st.find(next) != st.end())
                        next = st[next];
                    if (!vis.count(next)) {
                        vis.insert(next);
                        q.push({next, move + 1});
                    }
                
            }
        }
        return -1;
    }
};