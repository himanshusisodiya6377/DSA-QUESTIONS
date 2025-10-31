class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto it : arr) mp[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        while(k>0){
            int diff=pq.top().first;
            if(diff<=k){
                pq.pop();
                k-=diff;
            }
            else{
                break;
            }
        }
        return pq.size();
    }
};