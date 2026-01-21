class Solution {
public:
/*

Use a heap to store pairs (subsequence sum, index).

Each heap entry represents the best subsequence ending at that index.

While moving through the array, you:

Remove heap elements whose indices are farther than k from the current index.

Use the maximum value from the heap to extend the current element.

Also consider starting a new subsequence from the current element.

Push both possibilities into the heap.

Maintain a variable ans to track the maximum subsequence sum found so far.

What You’re Leveraging

The heap always gives the maximum subsequence sum available in the allowed range.

The index stored with each value helps ensure the distance constraint (k) is respected.

This avoids checking all k previous elements every time.
*/
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();

        priority_queue<pair<int,int>>pq; //value with lastest index

        int ans=INT_MIN;

        int i=n-1;

        while(i>=0){

            while(!pq.empty() && pq.top().second-i>k){
                ans=max(ans,pq.top().first);
                pq.pop();
            }

            if(!pq.empty()){
                auto p=pq.top();
                pq.push({p.first+nums[i],i});
            }

            pq.push({nums[i],i});
            i--;
        }

        return max(ans,pq.top().first);
    }
};