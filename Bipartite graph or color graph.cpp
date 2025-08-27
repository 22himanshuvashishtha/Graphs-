class Solution {
    private:
    bool bfs(int start,int n,vector<int>& v,vector<vector<int>>& graph){
        queue<int>q;
        q.push(start);
        v[start]=0; // here v is the color array ook sir 
        while(!q.empty()){
          int node=q.front();
          q.pop();
          for(auto it:graph[node]){
            if(v[it]==-1){
               v[it]= !v[node];
               q.push(it);
            }else if(v[it]==v[node]){
              return false;
            }
          }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>v(n,-1);
        for(int i=0;i<n;i++){
            if(v[i]== -1){
                if(bfs(i,n,v,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
