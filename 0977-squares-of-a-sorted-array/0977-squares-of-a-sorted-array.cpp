class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] * nums[i];
            pq.push(x);
        }
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
};