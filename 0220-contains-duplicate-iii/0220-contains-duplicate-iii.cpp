class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        set<int> ss(nums.begin(), nums.end());

        if(ss.size() == nums.size() && valueDiff == 0)
            return false;

        for(int i = 0; i < nums.size(); i++) {

            for(int j = i + 1; j < i + 1 + indexDiff; j++) {

                if(j >= nums.size())
                    break;

                if(abs((long long)nums[i] - (long long)nums[j]) <= valueDiff)
                    return true;
            }
        }

        return false;
    }
};