class Solution {
public:
    typedef pair<int,int> p;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        // Store original friend index by arrival time
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[times[i][0]] = i;
        }

        // Sort by arrival time
        sort(times.begin(), times.end());

        // Min-heaps
        priority_queue<p, vector<p>, greater<p>> pq;  // {leave_time, chair_number}
        priority_queue<int, vector<int>, greater<int>> freeChairs; // available chairs

        int nextChair = 0; // next unused chair number

        for (int i = 0; i < n; i++) {
            int arrival = times[i][0];
            int leave = times[i][1];
            int idx = mp[arrival];  // original friend index

            // Free up chairs of friends who have already left
            while (!pq.empty() && pq.top().first <= arrival) {
                freeChairs.push(pq.top().second);
                pq.pop();
            }

            int chair;
            if (!freeChairs.empty()) {
                chair = freeChairs.top();
                freeChairs.pop();
            } else {
                chair = nextChair++;
            }

            // If this is the target friend, return immediately
            if (idx == targetFriend) return chair;

            pq.push({leave, chair});
        }

        return -1; // should never reach here
    }
};
