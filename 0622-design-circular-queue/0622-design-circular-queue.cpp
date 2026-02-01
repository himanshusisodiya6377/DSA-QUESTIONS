class MyCircularQueue {
public:
    vector<int>nums;
    int front=-1,rear=-1;
    int N;
    int sz=0;
    MyCircularQueue(int k) {
        nums.resize(k,0);
        N=k;
    }
    
    bool enQueue(int value) {
        if(sz==N) return false;
        rear=(rear+1)%N;
        nums[rear]=value;
        if(front==-1) front++;
        sz++;
        return true;
    }
    
    bool deQueue() {
        if(sz==0) return false;
        front=(front+1)%N;
        sz--;
        return true;
    }
    
    int Front() {
        if(sz==0) return -1;
        return nums[front];
    }
    
    int Rear() {
        if(sz==0) return -1;
        return nums[rear];
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==N;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */