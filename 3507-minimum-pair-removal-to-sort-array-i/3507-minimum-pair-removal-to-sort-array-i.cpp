class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int minIndex = 0;

            // Find the leftmost adjacent pair with minimum sum
            for (int i = 0; i < nums.size() - 1; ++i) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIndex = i;
                }
            }

            // Merge the pair at minIndex
            nums[minIndex] = nums[minIndex] + nums[minIndex + 1];
            nums.erase(nums.begin() + minIndex + 1);
            count++;
        }

        return count;
    }
};
