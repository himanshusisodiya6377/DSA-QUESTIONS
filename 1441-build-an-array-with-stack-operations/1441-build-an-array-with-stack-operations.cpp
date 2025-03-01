class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m=target.size();
        vector<string>ans;
        int j=0,i=1;
       while(i<=n && j<m){
          if(target[j]==i){
            ans.push_back("Push");
            j++;
            i++;
          }
          else{
            ans.push_back("Push");
            ans.push_back("Pop");
             i++;
          }
       }
       return ans;
    }
};