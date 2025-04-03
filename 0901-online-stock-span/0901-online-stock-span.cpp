class StockSpanner {
public:
stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
            int span = 1;
            while (st.size() > 0 && st.top().first <= price) {
                span += st.top().second;
                st.pop();
            }
            st.push({price, span});
            // if (st.size() == 1)
            //     ans[i] = 0;
            // else {
            //     ans[i] = span;
            // }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */