class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        int n=s.length();
        vector<int>freq(26,0);
        
        deque<char>dq;
        
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']==1) dq.push_back(s[i]);
            
            while(!dq.empty() && freq[dq.front()-'a']>1){
                dq.pop_front();
            }
            
            if(dq.empty()) s[i]='#';
            else s[i]=dq.front();
        }
        return s;
    }
};