class Solution {
    private:
    void dfs(vector<vector<int>>& graph,int node,vector<vector<int>>& ans,vector<int>path){
        path.push_back(node);
        if(node ==graph.size()-1){
            ans.push_back(path);
        }else{
            for(int nnode:graph[node]){
                dfs(graph,nnode,ans,path);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(graph,0,ans,path);
        return ans;
    }
};
