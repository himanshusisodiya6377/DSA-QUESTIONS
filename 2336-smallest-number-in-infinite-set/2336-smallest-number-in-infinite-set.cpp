class SmallestInfiniteSet {
public:
    unordered_set<int>st;
    int sm=1;

    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++) st.insert(i);
    }

    int popSmallest() {
        int x=sm;
        st.erase(sm);
        for(int i=1;i<1001;i++){
            if(st.find(i)!=st.end()){
                sm=i;
                break;
            }
        }
        return x;
    }
    
    void addBack(int num) {
       if(st.find(num)==st.end()) st.insert(num);
       for(int i=1;i<1001;i++){
            if(st.find(i)!=st.end()){
                sm=i;
                break;
            }
        }
    }
};

