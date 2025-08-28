class Solution {
private:
    void dfs(int node, vector<int>& visited, vector<int> adj[], stack<int>& st) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, adj, st);
            }
        }
        st.push(node); 
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       
        vector<int> adj[V];
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v); 
        }

        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
