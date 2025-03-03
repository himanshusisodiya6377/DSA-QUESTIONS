class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans;
        queue<int>sm;
        queue<int>bg;
         queue<int>eq;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) sm.push(nums[i]);
            else if(nums[i]>pivot) bg.push(nums[i]);
            else eq.push(nums[i]);
        }
        while(sm.size()>0){
            ans.push_back(sm.front());
            sm.pop();
        }
          while(eq.size()>0){
            ans.push_back(eq.front());
            eq.pop();
        }
         while(bg.size()>0){
            ans.push_back(bg.front());
            bg.pop();
        }
       
        return ans;
    }
};