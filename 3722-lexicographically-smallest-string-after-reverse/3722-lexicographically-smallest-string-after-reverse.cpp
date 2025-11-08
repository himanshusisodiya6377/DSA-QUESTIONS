class Solution {
public:
    typedef pair<char,int> pp;
    string lexSmallest(string s) {
        int n=s.length();
        int i=0;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(int i=0;i<n;i++) pq.push({s[i],i});
        while(!pq.empty()){
            pair<char,int>p=pq.top();
            pq.pop();
            if(p.second==i){
                i++;
                continue;
            }
            else{
                if(i==0){
                    reverse(s.begin(),s.begin()+p.second+1);
                    return s;
                }
                else{
                    if(p.second!=s.length()-1){
                        i++;
                        continue;
                    }
                    else{
                        reverse(s.end()-(p.second),s.end());
                        return s;
                    }
                }
            }
        }
        return s;
    }
};