class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0,j=0;
        set<int>st;
        int ans=0;
        while(j<n){
          st.insert(fruits[j]);
          if(st.size()<=2){
            j++;
          }
          else{
            ans=max(ans,j-i);
            int num=fruits[i];
            while(fruits[i]==num) i++;
            // i=j;
            st.clear();
            j=i;
          }
        }
        ans=max(ans,j-i);
        return ans;
    }
};