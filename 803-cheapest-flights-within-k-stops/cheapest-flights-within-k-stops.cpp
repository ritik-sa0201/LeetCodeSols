class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];
            adj[u].push_back({v, cost});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if (stops > k) continue;

            for (auto& neighbour : adj[node]) {
                int nextNode = neighbour.first;
                int wt = neighbour.second;

                if (cost + wt < dist[nextNode]) {
                    dist[nextNode] = cost + wt;
                    q.push({stops + 1, {nextNode, cost + wt}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
