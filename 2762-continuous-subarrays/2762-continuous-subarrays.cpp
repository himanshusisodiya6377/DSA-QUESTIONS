class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        priority_queue<pair<int,int>> maxi;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > mini;

        int i = 0;
        long long ans = 0;

        for(int j = 0; j < nums.size(); j++) {

            maxi.push({nums[j], j});
            mini.push({nums[j], j});

            while(true) {

                while(!maxi.empty() && maxi.top().second < i)
                    maxi.pop();

                while(!mini.empty() && mini.top().second < i)
                    mini.pop();

                if(maxi.top().first - mini.top().first <= 2)
                    break;

                i++;
            }

            ans += (j - i + 1);
        }

        return ans;
    }
};