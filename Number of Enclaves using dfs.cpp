class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& visited,vector<vector<int>>& grid,int delrow[],int delcol[]){
        visited[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                dfs(nrow,ncol,visited,grid,delrow,delcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !visited[0][i]){
                dfs(0,i,visited,grid,delrow,delcol);
            }
            if(grid[n-1][i]==1 && !visited[n-1][i]){
                dfs(n-1,i,visited,grid,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(i,0,visited,grid,delrow,delcol);
            }
            if(grid[i][m-1]==1 && !visited[i][m-1]){
                dfs(i,m-1,visited,grid,delrow,delcol);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};
