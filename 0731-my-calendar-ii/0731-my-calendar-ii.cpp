class MyCalendarTwo {
public:
    map<int,int>mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        
        int cnt=0;
        for(auto &it : mp){
           cnt+=it.second;
           if(cnt==3){
            mp[startTime]--;
            mp[endTime]++;
            return false;
           }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */