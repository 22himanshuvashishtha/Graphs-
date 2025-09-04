class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    vector<vector<int>> visited(n, vector<int>(n, INT_MAX));
    queue<pair<int,pair<int,int>>>q;
    q.push({1,{0,0}});
    int delrow[]={-1,-1,-1,0,1,1,1,0};
    int delcol[]={-1,0,1,1,1,0,-1,-1};
    visited[0][0]=1;
    while(!q.empty()){
       auto it=q.front();
       int dis=it.first;
       int row=it.second.first;
       int col=it.second.second;
       q.pop();
        if (row == n - 1 && col == n - 1) {
                return dis;
        }
       for(int i=0;i<8;i++){
         int newrow=row+delrow[i];
         int newcol=col+delcol[i];

         if(newrow>=0 && newrow<n && newcol>=0 && newcol<n && grid[newrow][newcol] == 0 
           && dis+1 < visited[newrow][newcol]){
               visited[newrow][newcol]=dis+1;
               q.push({dis+1,{newrow,newcol}});
           }
       }
    }
    return -1;
    }
};
