class MedianFinder {
public:
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mini.size()==0 && maxi.size()==0) maxi.push(num);
        else{
           if(maxi.size()==mini.size()){
            if(num>maxi.top()) mini.push(num);
            else{
                maxi.push(num);
                mini.push(maxi.top());
                maxi.pop();
            }
           }
           else if(maxi.size()>mini.size()){
                if(num>maxi.top()) mini.push(num);
                else {
                maxi.push(num);
                mini.push(maxi.top());
                maxi.pop();
                }
           }
           else{
             if(num<mini.top()) maxi.push(num);
                else {
                mini.push(num);
                maxi.push(mini.top());
                mini.pop();
                }
           }

        }
    }

   
    
    double findMedian() {
        double ans=0;
        if(maxi.size()==mini.size()){
            ans=((double)mini.top()+(double)maxi.top())/2;
        }
        else{
           if(maxi.size()>mini.size()) return maxi.top();
           else return mini.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */