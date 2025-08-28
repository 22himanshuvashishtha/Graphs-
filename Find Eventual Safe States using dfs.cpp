class Solution {
    private:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathvis,vector<int>& check){
        visited[node]=1;
        pathvis[node]=1;
        check[node]=0;

        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it,adj,visited,pathvis,check)==true)return true;
            }else if(pathvis[it]){
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
       vector<int> visited(n, 0), pathvis(n, 0), check(n, 0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,visited,pathvis,check);          
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
