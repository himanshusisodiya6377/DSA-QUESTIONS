class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
     int n=s.length();
     int r=shifts.size();
     vector<int>diff(n,0);
     for(int i=0;i<r;i++){
        if(shifts[i][2]==0){
            diff[shifts[i][0]]-=1;
            if(shifts[i][1]+1<n) diff[shifts[i][1]+1]+=1;
        }
        else{
              diff[shifts[i][0]]+=1;
           if(shifts[i][1]+1<n) diff[shifts[i][1]+1]-=1;
        }
     }   
     for(int i=1;i<n;i++) diff[i]+=diff[i-1];
     for(int i=0;i<n;i++) diff[i]=diff[i]%26;
     string ans="";
     for(int i=0;i<n;i++){
         int x=s[i];
         x+=diff[i];
         if(x>122){
            int diffe=x-122;
            x=96+diffe;
         }
         else if(x<97){
            int diffe=96-x;
            x=122-diffe;
         }
           char ch=(char)x;
         ans.push_back(ch);
     }
     return ans;
    }
};