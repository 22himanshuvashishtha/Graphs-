class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);  
        vector<int> ways(n, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
        
        q.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;

        while (!q.empty()) {
            long long dis = q.top().first;
            int node = q.top().second;
            q.pop();
            if (dis > dist[node]) continue; 
            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int edw = it.second;

                if (dis + edw < dist[adjnode]) {
                    dist[adjnode] = dis + edw;
                    q.push({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node];
                } 
                else if (dis + edw == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
