#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u); // This line is removed if our graph is directed 
    }
    for(int i=1;i<=n;i++){
        cout<<i<<"-> ";
       for(auto x:adj[i]){
        cout<<x<<" ";
       }cout<<endl;
    }
}
