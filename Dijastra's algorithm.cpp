class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0]; 
            int v = edge[1]; 
            int w = edge[2]; 
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V, INT_MAX);

        pq.push({0, src});
        dist[src] = 0;
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dist[u]) {
                continue;
            }

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first; 
                int weight = neighbor.second; 

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};
