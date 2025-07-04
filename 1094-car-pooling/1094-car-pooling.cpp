class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int>v(1001,0);
        for(int i=0;i<n;i++){
            v[trips[i][1]]+=trips[i][0];
            if(trips[i][2]>1000) continue;
            else v[trips[i][2]]-=trips[i][0];
        }
        for(int i=1;i<1001;i++){
            v[i]+=v[i-1];
        }
        for(int i=0;i<1001;i++){
            if(v[i]>capacity) return false;
        }
        return true;
    }
};