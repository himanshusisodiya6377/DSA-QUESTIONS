class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // sort(arrays.begin(),arrays.end());
        int n=arrays.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            vector<int>temp=arrays[i];
            v.push_back({temp[0],i});
            v.push_back({temp[temp.size()-1],i});
        }
        sort(v.begin(),v.end());
        int j=0,k=v.size()-1;
        while(1){
            if(v[j].second!=v[k].second){
                return abs(v[j].first-v[k].first);
            }
            int diff1=abs(v[j+1].first-v[j].first);
            int diff2=abs(v[k-1].first-v[k].first);

            if(diff1<=diff2) j++;
            else k--;
        }
        return 0;
    }
};