class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost,
                                      int source, int target) {

        // -------------------- Build Graph --------------------
        // adj[u] = {v, travelTime}
        vector<vector<pair<int, int>>> adj(n);

        // Improvement 1:
        // Use const auto& since we are only reading the edges.
        for (const auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // -----------------------------------------------------
        // State = {minimumTime, currentNode, remainingPower}
        //
        // Improvement 2:
        // Use tuple instead of vector<long long>.
        //
        // Why?
        // - vector requires dynamic memory allocation.
        // - tuple is fixed-size and stored directly.
        // - Less memory overhead.
        // - Faster push/pop operations.
        // -----------------------------------------------------
        using State = tuple<long long, int, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        // dist[node][remainingPower] =
        // minimum time to reach 'node' with 'remainingPower' left.
        vector<vector<long long>> dist(
            n, vector<long long>(power + 1, LLONG_MAX));

        dist[source][power] = 0;
        pq.emplace(0LL, source, power);      // Improvement 3: emplace()

        while (!pq.empty()) {

            // Improvement 4:
            // Structured binding makes the code cleaner.
            auto [time, node, remainingPower] = pq.top();
            pq.pop();

            // Ignore outdated state.
            if (dist[node][remainingPower] != time)
                continue;

            // Not enough power to activate this node.
            if (remainingPower < cost[node])
                continue;

            // Destination reached.
            // No need to spend power here or move further.
            if (node == target)
                continue;

            // Spend power at current node.
            long long newPower = remainingPower - cost[node];

            // Improvement 5:
            // const auto& because we never modify adjacency entries.
            for (const auto &edge : adj[node]) {

                int nextNode = edge.first;
                int travelTime = edge.second;

                if (dist[nextNode][newPower] > time + travelTime) {

                    dist[nextNode][newPower] = time + travelTime;

                    // Improvement 6:
                    // emplace constructs tuple directly.
                    pq.emplace(dist[nextNode][newPower],
                               nextNode,
                               newPower);
                }
            }
        }

        //------------------------------------------------------
        // Find:
        // 1) Minimum travel time.
        // 2) If multiple answers have same minimum time,
        //    return the one with maximum remaining power.
        //------------------------------------------------------

        long long bestTime = LLONG_MAX;
        long long bestRemainingPower = -1;

        for (int rem = 0; rem <= power; rem++) {

            // Improvement 7:
            // Skip unreachable states immediately.
            if (dist[target][rem] == LLONG_MAX)
                continue;

            if (dist[target][rem] < bestTime) {
                bestTime = dist[target][rem];
                bestRemainingPower = rem;
            }
            else if (dist[target][rem] == bestTime) {
                // Same minimum time -> keep larger remaining power.
                bestRemainingPower = max(bestRemainingPower,
                                         (long long)rem);
            }
        }

        if (bestTime == LLONG_MAX)
            return {-1, -1};

        return {bestTime, bestRemainingPower};
    }
};