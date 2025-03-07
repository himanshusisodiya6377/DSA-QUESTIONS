class Solution {
public:
string convert(int n,int size){
       string result="";
       while(n>0){
        char x=(n%2)+'0';
        result.push_back(x);
        n/=2;
       }
       while(result.length()!=size){
        result.push_back('0');
       }
       reverse(result.begin(),result.end());
       return result;
}
   int convint(string s){
    int n=s.length();
    int ans=0;
    int j=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]!='0'){
            ans+=pow(2,j);
        }
        j++;
    }
    return ans;
   }
    string findDifferentBinaryString(vector<string>& nums) {
      unordered_set<int>st;
      for(int i=0;i<nums.size();i++){
        int numb=convint(nums[i]);
        st.insert(numb);
      }
      string ans;
      int m=nums.size();
      for(int i=0;i<=m;i++){
        if(st.find(i)==st.end()){
            ans=convert(i,m);
            break;
        }
      }
      return ans;
    }
};