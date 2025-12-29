class FreqStack {
public:
    int cnt;
    unordered_map<int, vector<int>> mp;
    FreqStack() {
        cnt = 0;
        // higher --> high prio
        // lower -->  lo prio
    }

    void push(int val) {
        mp[val].push_back(cnt);
        cnt++;
    }

    int pop() {
        int freq = 0;
        int val = -1;
        int last = -1;
        for (auto& it : mp) {
            if (it.second.size()!=0 && it.second.size() > freq) {
                if(val!=-1) mp[val].push_back(last);
                freq = it.second.size();
                val = it.first;
                last = it.second.back();
                it.second.pop_back();
            } else if (it.second.size()!=0 && it.second.size() == freq) {
                if (last < it.second.back()) {
                    if(val!=-1) mp[val].push_back(last);
                    freq = it.second.size();
                    val = it.first;
                    last = it.second.back();
                    it.second.pop_back();
                }
            }
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */