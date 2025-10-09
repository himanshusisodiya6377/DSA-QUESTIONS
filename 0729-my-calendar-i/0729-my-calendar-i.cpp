class MyCalendar {
public:
    vector<pair<int,int>>ans;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        bool flag=false;
        if(ans.size()==0){
            ans.push_back({startTime,endTime});
            return true;
        }
        else{
            for(int i=0;i<ans.size();i++){
                if(ans[i].second<=startTime){
                    //  ans.push_back({startTime,endTime});
                     flag=true;
                }
                else if(endTime<=ans[i].first){
                    //  ans.push_back({startTime,endTime});
                     flag=true;
                }
                else {
                    flag=false;
                    break;
                }
            }
        }
        if(flag) ans.push_back({startTime,endTime});
        return flag;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */