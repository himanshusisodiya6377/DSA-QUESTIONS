class SmallestInfiniteSet {
public:
    unordered_set<int> st;
   priority_queue<int, vector<int>, greater<int>> pq;
  
    SmallestInfiniteSet() {
        for (int i = 1; i < 1001; i++){
              st.insert(i);
              pq.push(i);
        }
    }

    int popSmallest() {
        int x = pq.top();
        st.erase(x);
        pq.pop();
        return x;
    }

    void addBack(int num) {
        if (st.find(num) == st.end()){
                st.insert(num);
                pq.push(num);
        }
    }
};
