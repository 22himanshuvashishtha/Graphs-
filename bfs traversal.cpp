#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (auto x : adj[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }

    vector<int> bfs;
    queue<int> q;
    vector<int> visited(n + 1, 0);

    q.push(1);         // start from node 1
    visited[1] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    cout << "BFS traversal: ";
    for (auto i : bfs) cout << i << " ";
    cout << "\n";

    return 0;
}
