class Solution {
  public:
  
    string get(int x){
        string s="";
        while(x>0){
            s+=to_string(x%2);
            x/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    vector<string> generateBinary(int n) {
        // code here
        vector<string>ans;
        for(int i=1;i<=n;i++){
            string a=get(i);
            
            ans.push_back(a);
            
        }
        return ans;
    }
};