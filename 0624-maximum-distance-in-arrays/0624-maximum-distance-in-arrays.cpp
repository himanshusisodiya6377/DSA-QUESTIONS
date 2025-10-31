class Solution {
public:
    typedef pair<int,int> p;
    int maxDistance(vector<vector<int>>& arrays) {
        // sort(arrays.begin(),arrays.end());
        int n=arrays.size();
        // vector<pair<int,int>>v;
        priority_queue<p>bg;
        priority_queue<p,vector<p>,greater<p>>sm;
        for(int i=0;i<n;i++){
            vector<int>temp=arrays[i];
            sm.push({temp[0],i});
            bg.push({temp[temp.size()-1],i});
        }
        // sort(v.begin(),v.end());
        // int j=0,k=v.size()-1;
        while(1){
            if(sm.top().second!=bg.top().second){
                return abs(sm.top().first-bg.top().first);
            }
            auto s=sm.top();
            sm.pop();
            auto b=bg.top();
            bg.pop();
            int diff1=abs(sm.top().first-s.first);
            int diff2=abs(bg.top().first-b.first);

            if(diff1<=diff2) {
                // j++;
                bg.push(b);
            }
            else {
                // k--;
                sm.push(s);
            }
        }
        return 0;
    }
};