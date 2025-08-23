#include <bits/stdc++.h>
using namespace std;

void dfs(int start,vector<int>adj[],vector<int>& visited,vector<int>& ls){
    visited[start]=1;
    ls.push_back(start);
    for(auto it:adj[start]){
        if(!visited[it]){
          dfs(it,adj,visited,ls);            
        }
    }
}
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
    // only printin adj. list for better understanding 
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (auto x : adj[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }

    vector<int>ls;
    vector<int> visited(n + 1, 0);
    int start=1;
    dfs(start,adj,visited,ls);

    cout << "DFS traversal: ";
    for (auto i : ls) cout << i << " ";
    cout << "\n";

    return 0;
}
