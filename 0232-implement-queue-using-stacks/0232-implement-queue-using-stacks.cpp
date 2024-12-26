class MyQueue {
public:
stack<int>st;
stack<int>temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
            while(st.size()>0){
                temp.push(st.top());
                st.pop();
            }
            int x=temp.top();
            temp.pop();
             while(temp.size()>0){
                st.push(temp.top());
                temp.pop();
            }
            return x;
      }
    int peek() {
            while(st.size()>0){
                temp.push(st.top());
                st.pop();
            }
            int x=temp.top();
             while(temp.size()>0){
                st.push(temp.top());
                temp.pop();
            }
            return x;
    }
    bool empty() {
     if(st.size()==0) return true;
     else return false;   
    }
};
