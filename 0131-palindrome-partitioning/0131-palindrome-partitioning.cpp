class Solution {
public:
    vector<vector<string>>ans;
    bool ispallindrome(string s,int start,int end){
         int i=start,j=end;

         while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
         }

         return true;
    }
    void solve(string s,int start,int end,vector<string>a){
        if(start>=end){
            ans.push_back(a);
            return;
        }

        // cout<<start<<" "<<end<<endl;

        for(int i=start;i<end;i++){
            // cout<<ispallindrome(s,start,i)<<" "<<i<<endl;
            if(ispallindrome(s,start,i)){
                // cout<<"yes"<<endl;
                a.push_back(s.substr(start,i-start+1));
                // cout<<s.substr(start,i-start+1)<<endl;
                solve(s,i+1,end,a);
                a.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
      vector<string>a;
      solve(s,0,s.length(),a);
      return ans;
    }
};