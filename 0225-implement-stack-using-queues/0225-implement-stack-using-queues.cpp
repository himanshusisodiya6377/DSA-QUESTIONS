class MyStack {
public:
    queue<int>q;
    queue<int>alt;

    int tp;
    MyStack() {
        tp=-1;
    }
    
    void push(int x) {
        q.push(x);
        tp=x;
    }
    
    int pop() {
        int n=q.size();
        while(n>1){
            alt.push(q.front());
            q.pop();
            n--;
        }
        int x=q.front();
        q.pop();
        while(alt.size()>0){
            q.push(alt.front());
            tp=alt.front();
            alt.pop();
        }
        return x;
    }
    
    int top() {
        // int n=q.size();
        // while(n>1){
        //     alt.push(q.front());
        //     q.pop();
        //     n--;
        // }
        // int x=q.front();
        // q.pop();
        // while(alt.size()>0){
        //     q.push(alt.front());
        //     alt.pop();
        // }
        // q.push(x);
        // return x;
        return tp;
    }
    
    bool empty() {
        return (q.size()>0 ? false : true);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */