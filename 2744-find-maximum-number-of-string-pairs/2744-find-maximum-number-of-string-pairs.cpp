class Solution {
public:
    string rev(string s){
        string temp=s;
         reverse(temp.begin(),temp.end());
         return temp;
    }
    int maximumNumberOfStringPairs(vector<string>& words) {
     int count=0;
     unordered_set<string>str;
     int n=words.size();
     for(int i=0;i<n;i++) str.insert(words[i]);
    for(int i=0;i<n;i++){
        string temp=rev(words[i]);
        if(temp!=words[i]){
             if(str.find(temp)!=str.end()) count++;
        str.erase(words[i]);
        }
     
    }
      return count;       
    }
};