class Solution {
public:
    typedef pair<long long, int> t;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<t, vector<t>, greater<t>> busyRooms;

        vector<int> count(n, 0);

        // initially all rooms are free
        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        for (auto &m : meetings) {
            long long start = m[0];
            long long end = m[1];

            // free rooms that are done before current meeting
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                // assign free room
                int room = freeRooms.top();
                freeRooms.pop();

                busyRooms.push({end, room});
                count[room]++;
            } else {
                // delay meeting
                auto [finishTime, room] = busyRooms.top();
                busyRooms.pop();

                long long newEnd = finishTime + (end - start);
                busyRooms.push({newEnd, room});
                count[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};