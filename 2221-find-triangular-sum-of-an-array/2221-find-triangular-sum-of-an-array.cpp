class Solution {
public:
    int triangularSum(vector<int>& nums) {
        long long n=nums.size();
        queue< long long>q;
        for(auto it: nums) q.push(it);
        // while(q.size()>0){
        //     cout<<q.front()<<endl;
        //     q.pop();
        // }  
        while(q.size()!=1){
             long long sz=q.size();
            while(sz>1 && q.size()!=1){
                long long x=q.front();
                q.pop();
                long long val=x+q.front();
                // cout<<val<<endl;
                q.push(val%10);
                sz--;
            }
            q.pop();
        //     while(q.size()>0){
        //     cout<<q.front()<<endl;
        //     q.pop();
        // } 
        }
        return q.front()%10;
        // return 0;
    }
};