class twoStacks {
  public:
    
    vector<int>arr;
    int i,j;
    twoStacks() {
        i=-1,j=100;
        arr.resize(100,-1);
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(i+1<j){
        arr[i]=x;
        i++;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(j-1>i){
        arr[j]=x;
        j--;
        }
        // code here
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        if(i>=0){
            i--;
            return arr[i];
        }
        return -1;
        // code here
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(j<100){
            j++;
            return arr[j];
        }
        return -1;
    }
};