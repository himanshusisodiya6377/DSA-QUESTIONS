class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int n=players.size();
        int m=trainers.size();

        int i=n-1,j=m-1;

        int ans=0;

        while(i>=0 && j>=0){
           
           if(players[i]<=trainers[j]){
             ans++;
             i--;
             j--;
           }
           else if(players[i]>trainers[j]) i--;
           else j--;
        }
       
        return ans;

    }
};