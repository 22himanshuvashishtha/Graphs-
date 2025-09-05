class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int>dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            q.pop();

            if(stops>k)continue;
            for(auto itr:adj[node]){
                int adjnode=itr.first;
                int adjw=itr.second;

                if(cost+adjw < dist[adjnode] && stops<=k){
                    dist[adjnode]=cost+adjw;
                    q.push({stops+1,{adjnode,cost+adjw}});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        
        return dist[dst];
    }
};
