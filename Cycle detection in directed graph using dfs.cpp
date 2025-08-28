class Solution {
    private:
    bool dfs(int node,vector<int>adj[],vector<int>& visited,vector<int>& pathvis){
        visited[node]=1;
        pathvis[node]=1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it,adj,visited,pathvis)==true)return true;
            }else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>visited(V,0),pathvis(V,0); // pathvisited is used to solve this problem becouse it is used to tell us that the cycle in on same path or not 
        vector<int> adj[V];
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            if(!visited[i]){
               if(dfs(i,adj,visited,pathvis)==true){
                return true;
              }    
            }
            
        }
        return false;
    }
};
