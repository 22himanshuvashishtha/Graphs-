// Bellman-Ford Algorithm additionally check for negitive cycle

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>visited(V,1e8);
        visited[src]=0;
        for(int i=0;i<V-1;i++){
            for(auto it:edges){
                int node1=it[0];
                int node2=it[1];
                int w=it[2];
                
                if(visited[node1]!=1e8 && w+visited[node1] < visited[node2]){
                    visited[node2]=w+visited[node1];
                }
            }
        }
        for(auto it:edges){
            int node1=it[0];
                int node2=it[1];
                int w=it[2];
                
                if(visited[node1]!=1e8 && w+visited[node1] < visited[node2]){
                    return {-1};
                }
        }
      return visited;    
    }
};
