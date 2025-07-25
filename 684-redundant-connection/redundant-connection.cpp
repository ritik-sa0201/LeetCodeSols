class Solution {
public:
    bool isConnected(int src, int dest, vector<vector<int>>& adj, int n) {
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest) return true;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

          
            if (isConnected(u, v, adj, n)) {
                return edge;
            }

    
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
