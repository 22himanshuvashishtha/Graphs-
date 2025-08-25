class Solution {
    private:
    bool dfs(int start,int parent,int visited[],vector<int> adj[]){
        visited[start]=1;
        for(auto nnode:adj[start]){
                if(!visited[nnode]){
                    if(dfs(nnode,start,visited,adj)==true)return true;
                }else if(visited[nnode] && parent!=nnode)return true;
            }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int visited[V]={0};  
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,visited,adj)==true) 
                return true;
            }
        }
        return false;
    }
};
