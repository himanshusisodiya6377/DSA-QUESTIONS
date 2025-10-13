class SummaryRanges {
public:
    
    vector<int>ans;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        ans.push_back(value);
        sort(ans.begin(),ans.end());
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ret;
        // for(auto it : ans){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int i=0,j=0;
        while(j<ans.size()){
            while(j<ans.size() && (ans[j]==ans[i] || ans[j]==(ans[j-1]+1) || ans[j]==ans[j-1])) j++;
            ret.push_back({ans[i],ans[j-1]});
            // cout<<i<<" "<<j;
            // cout<<endl;
            i=j;
        }
        if(j==ans.size() && i<ans.size()) ret.push_back({ans[i],ans[j-1]});
        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */