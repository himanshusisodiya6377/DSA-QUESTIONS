class ExamTracker {
public:
    vector<pair<long long,long long>>ans;
    vector<long long>pre;
    
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        ans.push_back({time,score});
        if(pre.size()>0) {
        long long sum=pre.back()+score;
        pre.push_back(sum);    
        }
        else pre.push_back(score);
    }
    
    long long totalScore(int startTime, int endTime) {
        auto it=lower_bound(ans.begin(),ans.end(),make_pair(startTime,LLONG_MIN))-ans.begin();
        if(it==ans.size()) return 0;

        cout<<it<<" ";
        if(ans[it].first>endTime) return 0;

        auto its=lower_bound(ans.begin(),ans.end(),make_pair(endTime,LLONG_MIN))-ans.begin();
        if(ans[its].first>endTime) its--;
        cout<<its<<endl;

        return pre[its]-(it>0 ? pre[it-1] : 0);
    }
};