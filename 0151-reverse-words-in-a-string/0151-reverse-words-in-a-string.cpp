class Solution {
public:
    string reverseWords(string s) {
        //this approach has TC O(n) and SC O(n) 
        //optimise approach 
/* maintain the two pointers i and j i will point to the first index of word and j pointing last of thw word than just creat substring of it and add in result
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            } // let to the right of word with increment in i
            reverse(s.begin() + left, s.begin() + right); //reverse
            s[right++] = ' ';
            left = right;
            i++;
        }
        s.resize(right - 1);
        return s;
    }
};
*/
    
    //   vector<string>v;
    //   string ans="";
    //   for(int i=0;i<s.length();i++){
    //     if(s[i]!=' ') ans.push_back(s[i]);
    //     else {
    //        if(ans!="") v.push_back(ans);
    //         ans="";
    //   }  
    //   }
    //     if(ans!="") v.push_back(ans);
    //   ans="";
    //   for(int i=v.size()-1;i>=0;i--){
    //       ans+=v[i];
    //       if(i!=0) ans+=" ";
    //   } 
    //   return ans;

    //approach 2
    // int n=s.length();
    // int i=0;
    // int l=0,r=0;
    // reverse(s.begin(),s.end());
    // while(i<n){
    //     while(i<n && s[i]!=' '){
    //         s[r++]=s[i++];
    //     }
    //     if(l<r){
    //          reverse(s.begin()+l,s.begin()+r);
    //     s[r]=' ';
    //     r++;
    //     l=r;
    //     }
    //     i++;
    // }
    // s=s.substr(0,r-1);
    // return s;

    //approach 3--tokenization
    reverse(s.begin(),s.end());
    stringstream ss(s);
    string words="";
    string ans="";
    while(ss>>words){
        reverse(begin(words),end(words));
        ans+=words;
        ans+=' ';
    }
    ans=ans.substr(0,ans.length()-1);
    // reverse(s.begin(),s.end());
    return ans;
    }
};