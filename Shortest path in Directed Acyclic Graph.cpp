// User function Template for C++
class Solution {
private:
    void topodfs(int node, vector<int>& visited, vector<pair<int,int>> adj[], stack<int>& st) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!visited[v]) {
                topodfs(v, visited, adj, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> adj[V];
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topodfs(i, visited, adj, st);
            }
        }
        vector<int> dis(V, INT_MAX);
        dis[0] = 0; // source = 0

        while (!st.empty()) {
            int n = st.top();
            st.pop();

            if (dis[n] != INT_MAX) {
                for (auto it : adj[n]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dis[n] + wt < dis[v]) {
                        dis[v] = dis[n] + wt;
                    }
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dis[i] == INT_MAX) dis[i] = -1;
        }

        return dis;
    }
};
