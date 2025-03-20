class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        //O(n) TC
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for (int i = 0; i < nums.size(); i++) {
        //     int x = nums[i] * nums[i];
        //     pq.push(x);
        // }
        // while (!pq.empty()) {
        //     int x = pq.top();
        //     pq.pop();
        //     ans.push_back(x);
        // }
        int i=0,j=nums.size()-1;
        int k=nums.size()-1;
        while(i<=j){
            int x=nums[i]*nums[i];
            int y=nums[j]*nums[j];
            if(x>y){
                ans[k]=x;
                k--;
                i++;
            }
            else{
                ans[k]=y;
                k--;
                j--;
            }
        }
        return ans;
    }
};