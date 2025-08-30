class Solution {
  public:
    
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        queue<int>q;
        vector<int>len(n,INT_MAX);
        len[src]=0;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(len[node]+1 < len[it]){
                    len[it]=1+len[node];
                    q.push(it);
                }
            }
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(len[i]!=INT_MAX){
                ans[i]=len[i];
            }
        }
        return ans;
    }
};
