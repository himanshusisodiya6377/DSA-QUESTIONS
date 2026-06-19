class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(target<=startFuel) return 0;

        sort(stations.begin(),stations.end());

        int ans=0;
        priority_queue<int>pq;
        int end=startFuel;

        int i=0;
        int n=stations.size();
        while(1){
            if(end>=target) return ans;
            //get thoose which are in curent range 
            while(i<n && stations[i][0]<=end) {
                pq.push(stations[i][1]);
                i++;
            }

            if(!pq.empty()){
                end+=pq.top();
                pq.pop();
            }
            else return -1;
            ans++;
            cout<<end<<endl;
        }
         if(end>=target) return ans;
        return ans;
    }
};