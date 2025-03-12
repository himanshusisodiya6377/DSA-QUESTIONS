class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        // vector<int> ans;
        // queue<int> sm;
        // queue<int> bg;
        // queue<int> eq;
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] < pivot)
        //         sm.push(nums[i]);
        //     else if (nums[i] > pivot)
        //         bg.push(nums[i]);
        //     else
        //         eq.push(nums[i]);
        // }
        // while (sm.size() > 0) {
        //     ans.push_back(sm.front());
        //     sm.pop();
        // }
        // while (eq.size() > 0) {
        //     ans.push_back(eq.front());
        //     eq.pop();
        // }
        // while (bg.size() > 0) {
        //     ans.push_back(bg.front());
        //     bg.pop();
        // }

        // return ans;
        vector<int>v(n,0);
        int sm=0,eq=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) sm++;
            else if(nums[i]==pivot) eq++;
        }
        int i=0,j=sm,k=sm+eq;
        for(int m=0;m<n;m++){
            if(nums[m]<pivot){
                v[i]=nums[m];
                i++;
            }
            else if(nums[m]==pivot){
                v[j]=nums[m];
                j++;
            }
            else{
                v[k]=nums[m];
                k++;
            }
        }
        return v;
    }
};