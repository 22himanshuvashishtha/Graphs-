class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dis(n,vector<int> (m,INT_MAX));
        dis[0][0]=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty()){
           auto it=pq.top();
           pq.pop();
           int distance=it.first;
           int row=it.second.first;
           int col=it.second.second;
           if(row==n-1 && col==m-1){
            return distance;
           }
           for(int i=0;i<4;i++){
              int newrow=row+delrow[i];
              int newcol=col+delcol[i];

              if(newrow>=0 && newrow<n && newcol>=0 && newcol<m){
                int neweffort=max(abs(heights[row][col]-heights[newrow][newcol]),distance);
                if(neweffort < dis[newrow][newcol]){
                    dis[newrow][newcol]=neweffort;
                    pq.push({neweffort,{newrow,newcol}});
                }
              }
           }

        }
        return 0;
    }
};
