class NumArray {
public:
    
    vector<int>pre;
    vector<int>v;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        v=nums;
        pre.push_back(nums[0]);
        for(int i=1;i<n;i++){
            pre.push_back(pre[pre.size()-1]+nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - v[index];
       v[index] = val;
    for (int i = index; i < pre.size(); i++) {
        pre[i] += diff;
    }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return pre[right];
        else return pre[right]-pre[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */