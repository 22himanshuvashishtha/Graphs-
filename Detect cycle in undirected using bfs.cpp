class Solution{
    public:
    bool detectcycle(int start,int visited[],vector<int> adj[]){
        visited[start]=1;
        queue<pair<int,int>>q;
        q.push({start,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto nnode:adj[node]){
                if(!visited[nnode]){
                    visited[nnode]=1;
                    q.push({nnode,node});

                }else if(visited[nnode] && parent!=nnode){
                    return true;
                }
            }
        }
    return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        int visited[V]={0};
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detectcycle(i,visited,adj)==true) return true;
            }
        }
        return false;
    }
};
