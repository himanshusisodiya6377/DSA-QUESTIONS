class SeatManager {
public:
    set<int>st;
    SeatManager(int n) {
        for(int i=1;i<=n;i++) st.insert(i);
    }
    
    int reserve() {
        auto x=st.begin();
        // cout<<x<<endl;
        int val=*x;
        st.erase(x);
        return val;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */