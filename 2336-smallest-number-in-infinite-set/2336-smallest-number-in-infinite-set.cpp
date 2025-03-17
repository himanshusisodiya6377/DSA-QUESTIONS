class SmallestInfiniteSet {
public:
//     unordered_set<int> st;
//    priority_queue<int, vector<int>, greater<int>> pq;
   set<int>st;
   int sm;
    SmallestInfiniteSet() {
        sm=1;
    }

    int popSmallest() {
        int result;
        if(!st.empty()){
           result=*st.begin();
           st.erase(st.begin());
        }
        else{
            result=sm;
            sm+=1;
        }
        return result;
    }

    void addBack(int num) {
        if (num>=sm || st.find(num) != st.end()){
                return ;
        }
        st.insert(num);
    }
};
