class SpecialStack {
  public:
    stack<int>st;
    unordered_map<int,int>mp;
    priority_queue<int>pq;
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        // Push an element into the stack
        st.push(x);
        mp[x]++;
        pq.push(x);
    }

    void pop() {
        // Remove the top element from the Stack
        int y=st.top();
        st.pop();
        mp[y]--;
    }

    int peek() {
        // Returns the top element
        if(st.size()>0)
        return st.top();
        
        return -1;
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMax() {
        // Return maximum element of Stack
        while(!pq.empty() && mp[pq.top()]<=0) pq.pop();
        if(!pq.empty()) return pq.top();
        return -1;
    }
};