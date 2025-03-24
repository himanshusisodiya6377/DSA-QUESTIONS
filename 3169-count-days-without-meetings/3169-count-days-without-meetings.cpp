class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int r=meetings.size();
        sort(meetings.begin(),meetings.end());
        int ans=0;
        //1 3 
        //5 7 
        //9 10
       for(int i=0;i<r-1;i++){
          if(meetings[i][1]<meetings[i+1][0]){
            ans+=meetings[i+1][0]-meetings[i][1]-1;
          }
          else if(meetings[i][1]<meetings[i+1][1]){
            continue;
          }
          else{
            meetings[i+1][1]=meetings[i][1];
          }
       }
       ans+=days-meetings[r-1][1];
       if(meetings[0][0]!=1){
        ans+=meetings[0][0]-1;
       }
       return ans;
    }
};