class MedianFinder {
public:
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;

    //easy just maintain two heap one min for large elemnts and max for min elements


    //optimization
   /* 
   Optimized Approach: Find Median from Data Stream (Numbers in Range 1–100)
Observation

When all incoming numbers lie in a small, fixed range (1 to 100), using heaps is unnecessary.
Instead of storing and ordering values, we can count their frequencies and use prefix sums to locate the median.

Data Structures Used

Frequency Array

freq[i] stores how many times number i has appeared.

Size is fixed (101), so memory usage is constant.

Total Count

An integer total to track the number of elements inserted so far.

Algorithm
Adding a Number

Increment freq[num].

Increment total.

This operation takes O(1) time.

Finding the Median

Median depends on the position in the sorted order, not on sorting itself.

Compute two middle positions:

mid1 = (total + 1) / 2

mid2 = (total + 2) / 2

Traverse numbers from 1 to 100, maintaining a cumulative count.

The first number where cumulative count ≥ mid1 is the first median value.

The first number where cumulative count ≥ mid2 is the second median value.

Median is the average of these two values.
   */
    
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