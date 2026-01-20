class Solution {
public:
    string reorganizeString(string s) {
        
        int n=s.size();

        vector<int>freq(26,0);

        for(auto &it : s) freq[it-'a']++;

        priority_queue<pair<int,char>>pq;

        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            pq.push({freq[i],i+'a'});
            cout<<freq[i]<<" "<<(i+'a')<<endl;
        }

        if(pq.top().first>(n+1)/2) return "";
        
        pair<int,char> p ={0,'#'};

        string ans="";
        while(!pq.empty()){

            auto [cnt,ch]=pq.top();
            pq.pop();

            ans.push_back(ch);
            cnt--;

            if(p.first>0){
                pq.push(p);
            }

            p={cnt,ch};

        }

        return ans;
    }
};