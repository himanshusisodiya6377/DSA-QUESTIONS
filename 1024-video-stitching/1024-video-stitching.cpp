class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());

        priority_queue<pair<int,int>>pq; //end first
        int j=0;
         while(j<clips.size() && clips[j][0]<=0) {
            pq.push({clips[j][1],clips[j][0]});
            j++;
        }
        int start=(!pq.empty() ? pq.top().first : 0);

        if(start==time) return 1;
       
        int ans=1;

        while(!pq.empty() && j<clips.size()){
        
           if(start>=time) return ans;

           while(j<clips.size() && clips[j][0]<=start) {
            pq.push({clips[j][1],clips[j][0]});
            j++;
        }
            //remove whose end before or equal to start
            while(!pq.empty() && pq.top().first<=start) pq.pop();

            ans++;
            start=pq.top().first;
             if(start>=time) return ans;
        }

        return -1;
    }
};