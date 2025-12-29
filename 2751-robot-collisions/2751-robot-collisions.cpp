class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hl,
                                      string dir) {
        vector<pair<int,int>> ans; //hlt idx
        int n = pos.size();
        vector<vector<int>> v; //vector ---> pos hlt 1 for R -1 for L index
        for (int i = 0; i < n; i++)
            v.push_back({pos[i], hl[i],(dir[i]=='R' ? 1 : -1) ,i});
        sort(v.begin(), v.end());
        stack<vector<int>> st; //hlt dir index
        for (int i = 0; i < n; i++) {
            int hlt = v[i][1];
            int  dr = v[i][2];
            int idx = v[i][3];
            
            int cnt = 0;
            bool flag = false;
           
            while (st.size() > 0 && (st.top()[1]==1 && dr == -1)) {
              
                if (st.top()[0] == hlt) {
                    st.pop();
                    flag = true;
                    
                    break;
                } else if (st.top()[0] > hlt) { // if i is small
                    st.top()[0]--;
                    flag = true;
                    break;
                } else {
                    // auto p=st.top();
                    st.pop();
                    hlt--;
                    // st.push({hlt-1,dr});
                }
            }
            if (!flag) {
                    st.push({hlt, dr,idx});
            }
        }

        while (!st.empty()) {
            ans.push_back({st.top()[2],st.top()[0]});
            st.pop();
        }

        // for(auto &it : ans) cout<<it.first<<" "<<it.second;
        // cout<<endl;
         
        sort(ans.begin(),ans.end());
        vector<int>a;
        for(auto &it : ans) a.push_back(it.second);
        // reverse(ans.begin(), ans.end());

        return a;
    }
};