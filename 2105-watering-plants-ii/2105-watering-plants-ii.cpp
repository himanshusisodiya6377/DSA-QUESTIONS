class Solution {
public:
    int minimumRefill(vector<int>& plants, int capA, int capB) {
        int i=0,j=plants.size()-1;
        
        int ans=0;
        int temp_A=capA;
        int temp_B=capB;

        while(i<j){

          if(temp_A>=plants[i]){
            temp_A-=plants[i];
          }   
          else {
            temp_A=capA-plants[i];
            ans++;
          }


          if(temp_B>=plants[j]){
            temp_B-=plants[j];
          }   
          else {
            temp_B=capB-plants[j];
            ans++;
          }

          i++;
          j--;
        }
        int n=plants.size();

        if(plants.size()%2!=0){
            if(max(temp_A,temp_B)<plants[i]) ans++;
        }

        return ans;
    }
};