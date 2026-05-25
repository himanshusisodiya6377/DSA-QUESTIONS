class Solution {
public:
    // Function to calculate the next index
    // The second % n handles negative results correctly in C++
    int getNext(int curr, vector<int>& nums){
        int n = nums.size();
        return ((curr + nums[curr]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        // We iterate through each index as a potential start of a cycle
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue; // Already visited/processed
            
            int slow = i, fast = i;
            // Capture the initial direction (positive or negative)
            int iniDir = nums[i];
            
            while(true){
                // 1. Direction Check: Slow pointer
                // If direction changes (product is negative) or becomes 0, path is invalid
                if(nums[slow] * iniDir <= 0) break;
                
                // 2. Direction Check: Fast pointer (current step)
                if(nums[fast] * iniDir <= 0) break;
                
                // 3. Direction Check: Fast pointer (next step)
                int nextFast = getNext(fast, nums);
                if(nums[nextFast] * iniDir <= 0) break;
                
                // Move pointers
                slow = getNext(slow, nums);
                fast = getNext(nextFast, nums);
                
                // Cycle detected
                if(slow == fast){
                    // Check for self-loop (cycle length must be > 1)
                    if(slow == getNext(slow, nums)) break;
                    else return true;
                } 
            }
            
            // Optimization: Mark the path as 0 (visited/invalid)
            // We only need to mark nodes that follow the same direction
            int curr = i;
            while(nums[curr] * iniDir > 0){
                int next = getNext(curr, nums);
                nums[curr] = 0;
                curr = next;
            }
        }
        return false;
    }
};