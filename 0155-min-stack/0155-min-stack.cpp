class MinStack {
public:
    vector<int>v;
    priority_queue<int,vector<int>,greater<int>> pq;
    stack<int>st;
    MinStack() {
        
    }

    /*
    ["MinStack","push","push","push","push","getMin","pop","getMin","pop","getMin","pop","getMin"]
[        [],     [2],    [0],   [3],   [0],   [],      [],    [],    [],     [],      [],[]]
*/
    
    void push(int val) {
        v.push_back(val);
        pq.push(val);
    }
    
    void pop() {
        // if(v[v.size()-1]==pq.top()){
        // v.pop_back();
        // pq.pop();
        // }
        // else v.pop_back();
        int n=v[v.size()-1];
        while(pq.top()!=n){
            int x=pq.top();
            pq.pop();
            st.push(x);
        }
        pq.pop();
        v.pop_back();
        while(st.size()!=0){
            int x=st.top();
            st.pop();
            pq.push(x);
        }
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return pq.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */